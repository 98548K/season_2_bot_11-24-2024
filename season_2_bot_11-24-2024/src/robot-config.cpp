#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

void  vexcodeInit( void );

//robot config.cpp stuff
motor LF = motor(PORT10, ratio18_1, true);
motor LM = motor(PORT1, ratio18_1, true);
motor LB = motor(PORT2, ratio18_1, true);
motor_group LeftDriveSmart = motor_group(LF, LM, LB);
motor RF = motor(PORT13, ratio18_1, false);
motor RM = motor(PORT12, ratio18_1, false);
motor RB = motor(PORT11, ratio18_1, false);
motor_group RightDriveSmart = motor_group(RF, RM, RB);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 40, mm, 1);
inertial Inertial1 = inertial(PORT15);
rotation Front_tracking = rotation(PORT15);
rotation Side_tracking = rotation(PORT21);
rotation claw_tracking = rotation(PORT16);
rotation intake_tracking = rotation(PORT4);
optical Optical1 = optical(PORT18);
optical Optical2 = optical(PORT16);

brain  Brain;
controller Controller1 = controller(primary);
motor Fintake = motor(PORT20,ratio6_1,false);
motor Bintake = motor(PORT14,ratio6_1,false);
motor_group intake = motor_group(Fintake,Bintake);
motor claw_mech = motor(PORT19, ratio6_1,false);
// Pistons
digital_out Clamp = digital_out(Brain.ThreeWirePort.H);
digital_out PTO = digital_out(Brain.ThreeWirePort.B);
digital_out descore_mech = digital_out(Brain.ThreeWirePort.E);
digital_out elevation = digital_out(Brain.ThreeWirePort.F);
digital_out color_sort = digital_out(Brain.ThreeWirePort.G);
