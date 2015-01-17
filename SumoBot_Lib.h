// SumoBot_Lib.h
#ifndef SumoBot_Lib_h
#define Sumobot_Lib_h
#define COEFICIENTE 16746.73
#define EXPONENTE -1.2134
#include "arduino.h"
class SumoBot
{
private:
	int pinDist, pinLight_R, pinLight_L, pinMotor_R1, pinMotor_R2, pinMotor_L1, pinMotor_L2, pinRed, pinGreen, pinBlue;
	/*DistanceSensor dist;
	LightSensor lightR, lightL;
	Motor motorR, motorL;
	Led led*/
public:
	SumoBot();
	float getDistance(float voltage);
};
class DistanceSensor
{
	private:
		int pin;
		float coeficiente, exponente;
	public:
		DistanceSensor(int pinInput);
		float anRead();
		float digRead();
		float distance();
		void setCoeficiente(float coef);
		void setExponente(float exp);
		float getCoeficiente();
		float getExponente();
};

class LightSensor
{
	private:
		int pin;
	public:
		LightSensor(int pinInput);
		float anRead();
		float digRead();
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

class Led
{
private:
	int pinRed, pinGreen, pinBlue;
public:
	Led(int red, int green, int blue);
	void red();
	void green();
	void blue();
	void off();
};

#endif
