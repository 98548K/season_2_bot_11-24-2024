#include "vex.h"

// CONSTANTS //


// Radius of tracking wheels in INCHES
const double WHEEL_RADIUS = 2;

// Inertial Orientation in RADIANS
const double startOrientation = 2.35619;

// Start Position. Depends on auton path
const double startXPos = -43.0;
const double startYPos = -58.25;

// Wheel Distance from Tracking Center
const double ForwardTrackingDistance = 3.5;
const double SidewaysTrackingDistance = 3;


// CALCULATED VALUES //


// Angles in DEGREEs
double forwardPos = 0;
double sidewaysPos = 0;

double previousForwardPos = 0;
double previousSidewaysPos = 0;

// Distance travelled per Loop
double deltaForward = 0;
double deltaSideways = 0;

// Distance Summations
double totalDeltaForward = 0;
double totalDeltaSideways = 0;

// Current Angle in RADIANS
double absoluteOrientation = startOrientation;

// Previous Angle in Radians
double previousOrientation = startOrientation;

// Change in Orientation
double deltaOrientation = 0;

// Average angle in RADIANS over the arc
double averageOrientationForArc = absoluteOrientation + (deltaOrientation / 2);

// Local Position Change
double deltaXLocal = 0;
double deltaYLocal = 0;

// Global Position Change
double deltaXGlobal = 0;
double deltaYGlobal = 0;

// Global Position on Field
double globalXPos = startXPos;
double globalYPos = startYPos;

int positionTracking() {
    while (true) {
        // Rotation sensor values in DEGREES
        forwardPos = Front_tracking.position(rotationUnits::deg);
        sidewaysPos = Side_tracking.position(rotationUnits::deg);

        // Converts degrees to RADIANS, then calculates distance travelled in INCHES
        deltaForward = ((forwardPos - previousForwardPos) * M_PI / 180) * WHEEL_RADIUS;
        deltaSideways = ((sidewaysPos - previousSidewaysPos) * M_PI / 180) * WHEEL_RADIUS;

        // Updates previous sensor values in DEGREES
        previousForwardPos = forwardPos;
        previousSidewaysPos = sidewaysPos;

        // Total change in encoders in INCHES (Mainly For Debugging)
        totalDeltaForward += deltaForward;
        totalDeltaSideways += deltaSideways;

        // Calculate robot orientation in RADIANS
        absoluteOrientation = Inertial1.heading(rotationUnits::deg) * M_PI / 180.0;

        // Calculates change in angle in RADIANS 
        deltaOrientation = absoluteOrientation - previousOrientation;

        // Updates previous orientation in RADIANS
        previousOrientation = absoluteOrientation;

        if (deltaOrientation == 0) { // If no rotation, it was just a translation
            deltaXLocal = deltaSideways;
            deltaYLocal = deltaForward;
        } else { // Else, do some boring math
            deltaXLocal = 2 * sin(deltaOrientation / 2.0) * ((deltaSideways / deltaOrientation) + SidewaysTrackingDistance);
            deltaYLocal = 2 * sin(deltaOrientation / 2.0) * ((deltaForward / deltaOrientation) - ForwardTrackingDistance); 
        }

        averageOrientationForArc = absoluteOrientation - (deltaOrientation / 2);

        deltaXGlobal = (deltaYLocal * sin(averageOrientationForArc)) + (deltaXLocal * cos(averageOrientationForArc));
        deltaYGlobal = (deltaYLocal * cos(averageOrientationForArc)) - (deltaXLocal * sin(averageOrientationForArc));

        globalXPos += deltaXGlobal;
        globalYPos += deltaYGlobal;

        Brain.Screen.setFillColor(orange);

        task::sleep(10);
    }
    return 0;
}

void setPosition(double x, double y, double heading) {
    Inertial1.setHeading(heading, degrees);

    absoluteOrientation = heading * M_PI / 180;

    globalXPos = x;
    globalYPos = y;
}