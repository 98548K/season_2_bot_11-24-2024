#include "vex.h"

bool draw = true;
int auton = 0;

//Menu for right side autons
void Menu1() {
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(blue);
  Brain.Screen.drawRectangle(0, 0, 250,117);
  Brain.Screen.setFillColor(red);
  Brain.Screen.drawRectangle(0, 117, 250,117);
  Brain.Screen.setFillColor(blue);
  Brain.Screen.drawRectangle(250, 0, 250,117);
  Brain.Screen.setFillColor(red);
  Brain.Screen.drawRectangle(250, 117, 250,117);
  Brain.Screen.setCursor(3,3);
  Brain.Screen.setFillColor(blue);
  Brain.Screen.setPenColor(white);
  Brain.Screen.print("Left Blue");
  Brain.Screen.setCursor(9,3);
  Brain.Screen.setFillColor(red);
  Brain.Screen.setPenColor(white);
  Brain.Screen.print("Left Red");
  Brain.Screen.setCursor(3,33);
  Brain.Screen.setFillColor(blue);
  Brain.Screen.setPenColor(white);
  Brain.Screen.print("Left Blue Elims");
  Brain.Screen.setCursor(9,33);
  Brain.Screen.setFillColor(red);
  Brain.Screen.setPenColor(white);
  Brain.Screen.print("Left Red Elims");
  
  //touch screen
  //left side menu
  while(true) {
    Brain.Screen.setFillColor(blue);
      if (Brain.Screen.xPosition()< 250){
      if (Brain.Screen.yPosition()< 140){
        auton = 2;
        Brain.Screen.setCursor(1,1);
        Brain.Screen.print("Left Blue      ");
      } 
      }
      if (Brain.Screen.xPosition()< 250){
      if (Brain.Screen.yPosition()> 120){
        auton = 3;
        Brain.Screen.setCursor(1,1);
        Brain.Screen.print("Left Red       ");
      }
      } 
      if (Brain.Screen.xPosition()> 240){
      if (Brain.Screen.yPosition()< 140){
        auton = 4;
        Brain.Screen.setCursor(1,1);
        Brain.Screen.print("Left Blue Elims");
      }
      } 
      if (Brain.Screen.xPosition()> 240){
      if (Brain.Screen.yPosition()> 120){
        auton = 5;
        Brain.Screen.setCursor(1,1);
        Brain.Screen.print("Left Red Elims ");
      }
      } 
      wait(20, msec);
  

      // Back button code
      if (Controller1.ButtonX.pressing()){
        Brain.Screen.clearScreen();
        draw = true;
        wait(0.1, sec);
        return;
      }
      wait(20, msec);
  }
}
//Menu for right side autons
void Menu2() {
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(blue);
  Brain.Screen.drawRectangle(0, 0, 250,117);
  Brain.Screen.setFillColor(red);
  Brain.Screen.drawRectangle(0, 117, 250,117);
  Brain.Screen.setFillColor(blue);
  Brain.Screen.drawRectangle(250, 0, 250,117);
  Brain.Screen.setFillColor(red);
  Brain.Screen.drawRectangle(250, 117, 250,117);
  Brain.Screen.setCursor(3,3);
  Brain.Screen.setFillColor(blue);
  Brain.Screen.setPenColor(white);
  Brain.Screen.print("Right Blue");
  Brain.Screen.setCursor(9,3);
  Brain.Screen.setFillColor(red);
  Brain.Screen.setPenColor(white);
  Brain.Screen.print("Right Red");
  Brain.Screen.setCursor(3,33);
  Brain.Screen.setFillColor(blue);
  Brain.Screen.setPenColor(white);
  Brain.Screen.print("Right Blue Elims");
  Brain.Screen.setCursor(9,33);
  Brain.Screen.setFillColor(red);
  Brain.Screen.setPenColor(white);
  Brain.Screen.print("Right Red Elims");
  wait(0.5, sec);
  //touch screen
  //right side menu
    while(true) {
    Brain.Screen.setFillColor(blue);
      if (Brain.Screen.xPosition()< 250){
      if (Brain.Screen.yPosition()< 140){
        auton = 6;
        Brain.Screen.setCursor(1,1);
        Brain.Screen.print("Right Blue      ");
      } 
      }
      if (Brain.Screen.xPosition()< 250){
      if (Brain.Screen.yPosition()> 120){
        auton = 7;
        Brain.Screen.setCursor(1,1);
        Brain.Screen.print("Right Red       ");
      }
      } 
      if (Brain.Screen.xPosition()> 240){
      if (Brain.Screen.yPosition()< 140){
        auton = 8;
        Brain.Screen.setCursor(1,1);
        Brain.Screen.print("Right Blue Elims");
      }
      } 
      if (Brain.Screen.xPosition()> 240){
      if (Brain.Screen.yPosition()> 120){
        auton = 9;
        Brain.Screen.setCursor(1,1);
        Brain.Screen.print("Right Red Elims ");
      }
      } 
      wait(20, msec);

      // Back button code
      if (Controller1.ButtonX.pressing()){
        Brain.Screen.clearScreen();
        draw = true;
        wait(0.1, sec);
        return;
      }
      wait(20, msec);
    }
  }
//Menu for right side autons
void initial_menu() {
  while (true){
    if (draw == true){
      Brain.Screen.clearScreen();
      Brain.Screen.setFillColor(white);
      Brain.Screen.drawRectangle(0, 0, 180,240);
      Brain.Screen.setFillColor(black);
      Brain.Screen.drawRectangle(300, 0, 180,240);
      Brain.Screen.setFillColor(ClrPurple);
      Brain.Screen.drawRectangle(180, 0, 120,120);
      Brain.Screen.setFillColor(ClrPink);
      Brain.Screen.drawRectangle(180, 120, 120,120);
      Brain.Screen.setCursor(6,9);
      Brain.Screen.setFillColor(white);
      Brain.Screen.setPenColor(black);
      Brain.Screen.print("Left");
      Brain.Screen.setCursor(6,39);
      Brain.Screen.setFillColor(black);
      Brain.Screen.setPenColor(white);
      Brain.Screen.print("Right");
      Brain.Screen.setCursor(3,22);
      Brain.Screen.setFillColor(ClrPurple);
      Brain.Screen.setPenColor(white);
      Brain.Screen.print("Skills");
      Brain.Screen.setCursor(9,20);
      Brain.Screen.setFillColor(ClrPink);
      Brain.Screen.setPenColor(white);
      Brain.Screen.print("Calibrate");
      draw = false;
    }
  //touch screen
    //left side menu
    Brain.Screen.setFillColor(white);
    if (Brain.Screen.pressing()){
     if (Brain.Screen.xPosition()< 180){
      Menu1();
     } 
     //Calibrate
     if (Brain.Screen.xPosition()> 180){
       if (Brain.Screen.xPosition()< 300){
        if (Brain.Screen.yPosition()> 120){
          Inertial1.calibrate();
          Brain.Screen.setCursor(1,1);
          Brain.Screen.setFillColor(white);
          Brain.Screen.setPenColor(black);
          Brain.Screen.print("Calibrating      ");
          Front_tracking.setPosition(0,degrees);
          Side_tracking.setPosition(0,degrees);
          wait (1, sec);
          Brain.Screen.setCursor(1,1);
          Brain.Screen.print("3               ");
          wait (1, sec);
          Brain.Screen.setCursor(1,1);
          Brain.Screen.print("2               ");
          wait (1, sec);
          Brain.Screen.setCursor(1,1);
          Brain.Screen.print("1               ");
          wait (1, sec);
          Brain.Screen.setCursor(1,1);
          Brain.Screen.print("Calibrated      ");
        }
      }
    } 
    //Skills
    if (Brain.Screen.xPosition()> 180){
      if (Brain.Screen.xPosition()< 300){
       if (Brain.Screen.yPosition()< 120){
         auton = 1;
         Brain.Screen.setCursor(1,1);
         Brain.Screen.setFillColor(white);
         Brain.Screen.setPenColor(black);
         Brain.Screen.print("Skills         ");
       }
      }
     }
     //Right side menu  
     if (Brain.Screen.xPosition()> 300){
      Menu2();
     }  
    }
    wait(20, msec);
  }
}