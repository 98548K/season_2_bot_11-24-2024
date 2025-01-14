#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "v5.h"
#include "v5_vcs.h"

#include "robot-config.h"
#include "other_functions.h"
#include "auton_selector.h"
#include "autons.h"
#include "PID.h"
#include "odometry.h"
#include "RC.h"
#include "pre-auton.h"
#include "autonomous.h"
#include "usercontrol.h"
#include "other_functions.h"

#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)