#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

competition Competition;
void  vexcodeInit( void );

int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}