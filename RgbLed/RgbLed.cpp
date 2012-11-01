
#include "Arduino.h"
#include "RgbLed.h"

RgbLed::RgbLed()
{
}

void RgbLed::setup(int rPin, int gPin, int bPin, int id)
{
    _rPin = rPin;
	_gPin = gPin;
	_bPin = bPin;
	_id = id;
	
    pinMode(rPin, OUTPUT); 
    pinMode(gPin, OUTPUT); 
	pinMode(bPin, OUTPUT); 
	
	_numSteps = 50;
	_currentStep = 0;
}

void RgbLed::update()
{
    int rDiff = _rValGoal - _rVal;
    if (abs(rDiff) > 1)
	    _rVal = _rVal + rDiff/_numSteps;
	int gDiff = _gValGoal - _gVal;
    if (abs(gDiff) > 1)
	    _gVal = _gVal + gDiff/_numSteps;
	int bDiff = _bValGoal - _bVal;
    if (abs(rDiff) > 1)
	    _bVal = _bVal + bDiff/_numSteps;
		

    analogWrite(_rPin, _rVal);
    analogWrite(_gPin, _gVal);
    analogWrite(_bPin, _bVal); 
}

void RgbLed::setColor(int r, int g, int b)
{
    setGoal(r, g, b);
	_rVal = r;
	_gVal = g;
	_bVal = b;
    analogWrite(_rPin, r);
    analogWrite(_gPin, g);
    analogWrite(_bPin, b);
}

void RgbLed::setGoal(int r, int g, int b)
{
    _rValGoal = r;
	_gValGoal = g;
	_bValGoal = b;
}