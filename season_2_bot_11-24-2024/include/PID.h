#pragma once

class PID
{
private:
  void DataLogCheck();
  void DataLogEnd();
public:

  double P;
  double I;
  double D;
  double R;

  double IntegralCap;
  double SpeedCap;

  double RampUp = 0;
  double Error = 0;
  double PreviousError = 0;

  double PIDSpeed;
  double SmartSpeed;

  double Integral = 0;
  double Derivative = 0;
  bool HasRampedUp = false;

  bool HasReachedEnd = false;
  double TimeReachedEnd = 0;
  double Timeout;
  double SettleTime;
  double Time = 0;

  bool RanOnce = false;
  bool *NotDone;

  PID(double p, double i, double d, double r, double integral_cap, double speed_cap, bool *not_done, double timeout, double settle_time);
    

  double Update(double error, double dt);

};

 
int GetSign(double number);