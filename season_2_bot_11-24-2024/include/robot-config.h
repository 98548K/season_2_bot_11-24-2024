using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern drivetrain Drivetrain;
extern motor_group LeftDriveSmart;
extern motor_group RightDriveSmart;
extern motor Fintake;
extern motor Bintake;
extern motor_group intake;
extern motor claw_mech;
extern digital_out Clamp;
extern digital_out descore_mech;
extern digital_out PTO;
extern digital_out color_sort;
extern digital_out elevation;
extern inertial Inertial1;
extern rotation Front_tracking;
extern rotation Side_tracking;
extern rotation claw_tracking;
extern rotation intake_tracking;
extern optical Optical1;
extern optical Optical2;

 
void  vexcodeInit( void );