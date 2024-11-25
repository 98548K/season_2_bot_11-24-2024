#include "vex.h"

void blue_detected() {
  if (Optical1.color() == blue){
    wait (.15,sec);
    color_sort.set(true);
    wait (.1,sec);
    color_sort.set(false);
  }
  else if (Optical1.color() == ClrSkyBlue){
    wait (.15,sec);
    color_sort.set(true);
    wait (.1,sec);
    color_sort.set(false);
  }
  else if (Optical1.color() == ClrLightBlue){
    wait (.15,sec);
    color_sort.set(true);
    wait (.1,sec);
    color_sort.set(false);
  }
}
void red_detected() {
  wait (.15,sec);
  if (Optical1.color() == red){
    color_sort.set(true);
    wait (.1,sec);
    color_sort.set(false);
  }
}


void goal_stop() {
  if (Optical2.color() == yellow) {
    Drivetrain.stop();
    Clamp.set(false);
    intake.spinFor(-1500,degrees);
  }
}

void funny_prank() {
  Optical1.setLightPower(100,pct);
  Optical1.objectDetected(blue_detected);
  Optical1.objectDetected(red_detected);
  wait (3,sec);
}
      

void PID_turn(double LeftVelocity,double RightVelocity,double inches_traveled) {
  LeftDriveSmart.setVelocity(LeftVelocity, pct);
  RightDriveSmart.setVelocity(RightVelocity,pct);
  Drivetrain.driveFor(inches_traveled, inches,false);
  wait(1,sec);
  Drivetrain.stop();
}

void Reset_Both_Sides(double same_velocity) {
  LeftDriveSmart.setVelocity(same_velocity, pct);
  RightDriveSmart.setVelocity(same_velocity,pct);
}

double targetX = 0;
double targetY = 0;

double localXError = 0;
double localYError = 0;

double targetOrientation = 0;

double wrapAngleDeg(double angle) {
    angle = fmod(angle + 180.0, 360.0);
    return (angle >= 0) ? angle - 180.0 : angle + 180.0;
}

double getDistance(double x1, double y1, double x2, double y2) {
    double a = (x1 - x2) * (x1 - x2);
    double b = (y1 - y2) * (y1 - y2);
    double dist = sqrt(a + b);

    return dist;
}

void turnToHeading(double heading, double turnSpeed) {
    bool notDone = true;
    PID turnPid = PID(0.7815, 0.00635, 3.97, 2, 3, 100, &notDone, 600, 100);
    
    double error = wrapAngleDeg(heading - Inertial1.heading());
    double previousError = error;
    double previousTime = Brain.Timer.system();

    while (notDone) {
        double error = wrapAngleDeg(heading - Inertial1.heading());
        double previousError = error;

        double speed = turnPid.Update(error, (Brain.Timer.system() - previousTime));

        LeftDriveSmart.spin(forward, speed * (turnSpeed / 100), percent);
        RightDriveSmart.spin(reverse, speed * (turnSpeed / 100), percent);

        previousTime = Brain.Timer.system();

        wait(10, msec);
    }

    LeftDriveSmart.stop();
    RightDriveSmart.stop();
}

void pointAt(double x, double y, double turnSpeed, vex::directionType dir) {
    targetOrientation = atan2(x - globalXPos, y - globalYPos);
    if (dir == forward) {
        turnToHeading(targetOrientation * (180/M_PI), turnSpeed);
    } else if (dir == reverse) {
        turnToHeading(targetOrientation * (180/M_PI) + 180, turnSpeed);
    }
}

void driveFor(double distance, double speed) {
    double targetHeading = Inertial1.heading();
    double encoderStart = Front_tracking.position(turns);


    bool driving = true;
    bool turning = true;
    PID drivePID = PID(8, 0.01, 24.105, 0.2, 10, 100, &driving, 2000, 150);
    PID turnPID = PID(0.7815, 0, 3.97, 2, 8, 100, &turning, 2000, 100);

    double driveError = distance;
    double turnError = wrapAngleDeg(targetHeading - Inertial1.heading());

    double previousTime = Brain.Timer.system();

    while (driving) {
        double encoderChange = Front_tracking.position(turns) - encoderStart;
        double inchesMoved = encoderChange * 3 * M_PI; // Circumference of Wheels

        driveError = distance - inchesMoved;

        turnError = wrapAngleDeg(targetHeading - Inertial1.heading());

        double dt = (Brain.Timer.system() - previousTime);

        double driveOutput = drivePID.Update(driveError, dt);
        double turnOutput = turnPID.Update(turnError, dt);

        LeftDriveSmart.spin(forward, (driveOutput + turnOutput) * (speed / 100), percent);
        RightDriveSmart.spin(forward, (driveOutput - turnOutput) * (speed / 100), percent);

        previousTime = Brain.Timer.system();

        wait(10, msec);

        Brain.Screen.printAt(50, 50, "%f", driveError);
    }

    LeftDriveSmart.stop();
    RightDriveSmart.stop();
}

void driveTo(double x, double y, double speed, vex::directionType dir) {
    pointAt(x, y, 100, dir);

    if (dir == forward) {
        double dist = getDistance(globalXPos, globalYPos, x, y);
        driveFor(dist, speed);
    }

    if (dir == reverse) {
        double dist = getDistance(globalXPos, globalYPos, x, y);
        driveFor(-dist, speed);
    }
}