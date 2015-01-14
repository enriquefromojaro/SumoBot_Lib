// SumoBot_Lib.h
#ifndef SumoBot_Lib_h
#define Sumobot_Lib_h
#define COEFICIENTE 16746.73
#define EXPONENTE -1.2134
#include "arduino.h"
class SumoBot
{
public:
	float getDistance(float voltage);
};
class DistanceSensor
{
	private:
		int pin;
	public:
		DistanceSensor(int pinInput);
		float analogVoltage();
		float digitalVoltage();
		float distance();
};

class LightSensor
{
	private:
		int pin;
	public:
		LightSensor(int pinInput);
		float analogVoltage();
		float digitalVoltage();
		boolean black();
};

class Motor
{
private:
	int pin[2];
public:
	Motor(int pin1, int pin2, char side);
	void forward();
	void backward();
	void stop();
};

#endif
