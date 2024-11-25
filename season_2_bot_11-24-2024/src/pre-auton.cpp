#include "vex.h"

void pre_auton(void) {
  vexcodeInit();
  intake.setVelocity(100,pct);
  //initial_menu();


  Brain.Screen.setCursor(9, 7);
  Brain.Screen.print(globalXPos);
  Brain.Screen.setCursor(6, 7);
  Brain.Screen.print(globalYPos);
  
}