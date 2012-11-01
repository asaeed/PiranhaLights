
#ifndef RGBLED_h
#define RGBLED_h

#include "Arduino.h"

class RgbLed
{
public:
  RgbLed();
  void setup(int rPin, int gPin, int bPin, int id);
  void update();
  void setColor(int rVal, int gVal, int bVal);
  void setGoal(int rVal, int gVal, int bVal);
  
private:
  int _id;
  
  int _rPin;
  int _gPin;
  int _bPin;
  
  int _rVal;
  int _gVal;
  int _bVal;
  
  int _rValGoal;
  int _gValGoal;
  int _bValGoal;
  
  int _numSteps;
  int _currentStep;

};
#endif 
