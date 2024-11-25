extern int positionTracking();

extern const double WHEEL_RADIUS;

extern const double startOrientation;

extern const double startXPos;
extern const double startYPos;

extern const double ForwardTrackingDistance;
extern const double SidewaysTrackingDistance;

extern double forwardPos;
extern double sidewaysPos;

extern double previousForwardPos;
extern double previousSidewaysPos;

extern double deltaForward;
extern double deltaSideways;

extern double totalDeltaForward;
extern double totalDeltaSideways;

extern double absoluteOrientation;

extern double previousOrientation;

extern double deltaOrientation;

extern double averageOrientationForArc;

extern double deltaXLocal;
extern double deltaYLocal;

extern double deltaXGlobal;
extern double deltaYGlobal;

extern double globalXPos;
extern double globalYPos;

extern void setPosition(double x, double y, double heading);

void setAuton();