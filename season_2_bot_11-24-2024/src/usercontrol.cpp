#include "vex.h"

bool Clamping = true;
bool elevate = false;
bool tier_1 = false;
bool notstuck = true;
bool color_sortTrue = true;

void usercontrol(void) {
  //enablePID_Drive = false;
  // User control code here, inside the loop
  while (1) {
    claw_mech.setVelocity(100, pct);
    intake.setVelocity(100, pct);
    Drivetrain.setDriveVelocity(100, pct);
    if (Controller1.ButtonUp.pressing()) {
      notstuck = true;
      if (notstuck == true) {
      claw_mech.setVelocity(100, pct);
      while (claw_tracking.position(degrees) >= 10){
            claw_mech.spin(reverse);
          }
          wait (.1,sec);
          claw_mech.spinFor(140,degrees);
          claw_mech.stop(hold);
      }
    }
    if (Controller1.ButtonRight.pressing()) {
        notstuck = false;
        wait (.1,sec);
        claw_mech.spinFor(60,degrees);
        claw_mech.stop(hold);
    }
    // Clamp toggle
    if (Controller1.ButtonY.pressing()) {
      if (Clamping == true){
        Clamping = false;
        wait(.1, sec);        
      }
       else if (Clamping == false){
        Clamping = true;
        wait(.1, sec);
      }
    }
    Clamp.set(Clamping);

    // Color sort toggle
    if (Controller1.ButtonDown.pressing()) {
      if (color_sortTrue == false){
        color_sortTrue = true;
        wait(.1, sec);        
      }
       else if (color_sortTrue == true){
        color_sortTrue = false;
        wait(.1, sec);
      }
    }
    color_sort.set(color_sortTrue);


    // Descore mech toggle    
  if (Controller1.ButtonB.pressing()) {
      if (elevate == false){
        elevate = true;
        wait(.1, sec);
      }
       else if (elevate == true){
        elevate = false;
        wait(.1, sec);
      }
    }
    descore_mech.set(elevate);

    // Elevation toggle
  /*if (Controller1.ButtonDown.pressing()) {
      if (tier_1 == false){
        claw_mech.setVelocity(100,pct);
        while (claw_tracking.position(degrees) >= 10){
            claw_mech.spin(reverse);
          }
          wait (.1,sec);
          claw_mech.spinFor(240,degrees);
          claw_mech.stop(hold);
          elevation.set(true);
          claw_mech.spinFor(-140,degrees);
          claw_mech.stop(hold);
          tier_1 = true;
      }
       else if (tier_1 == true){
        tier_1 = false;
        wait(.1, sec);
      }
    }
    elevation.set(tier_1);*/

    // Intake Spinner
    if (Controller1.ButtonL1.pressing()) {
        intake.spin(reverse);
        // insert function here
    }else if (Controller1.ButtonL2.pressing()) {
      intake.spin(forward);
    }else if (true){
      intake.stop();
    }
  LeftDriveSmart.setVelocity(100, pct);
  RightDriveSmart.setVelocity(100,pct);
  
  
  
    wait(.1, sec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
   }
}