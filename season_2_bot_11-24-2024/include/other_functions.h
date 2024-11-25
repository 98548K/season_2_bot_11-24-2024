void blue_detected();

void red_detected();

void red_stop();

void blue_stop();

void funny_prank();

void PID_turn(double LeftVelocity,double RightVelocity,double inches_traveled);

void Reset_Both_Sides(double same_velocity);

void goal_stop();

extern double targetX;
extern double targetY;
extern double targetOrientation;

void turnToHeading(double heading, double turnSpeed);
void pointAt(double x, double y, double turnSpeed, vex::directionType dir);
void driveFor(double distance, double speed);
void driveTo(double x, double y, double speed, vex::directionType dir);