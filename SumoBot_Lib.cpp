
#include "SumoBot_Lib.h"
#include "arduino.h"
#define COEFICIENTE 16746.73
#define EXPONENTE -1.2134
float SumoBot::getDistance(float voltage)//Retorna la distancia en centímetros (cm) según la formula del SHARP en función del voltaje introducido
{
	return COEFICIENTE * float(pow(voltage,EXPONENTE));
}

//--------------------------------DistanceSensor-----------------------------------------------

DistanceSensor::DistanceSensor(int pinInput)//Constructor del Sensor de Distancia
{
	pin=pinInput;
	pinMode(pin, INPUT);

}
float DistanceSensor::distance()//Retorna la distancia en centímetros (cm) según la formula del SHARP
{
	return COEFICIENTE * float(pow(analogRead(pin),EXPONENTE));
}

float DistanceSensor::analogVoltage()
{
	return analogRead(pin);
}

float DistanceSensor::digitalVoltage()
{
	return digitalRead(pin);
}

//--------------------------LightSensor-----------------------------------------------------
LightSensor::LightSensor(int pinInput)//Constructor del Sensor de luz. LLeva como parámetro el pin en el que está
{
	pin=pinInput;
	pinMode(pin, INPUT);

}

boolean LightSensor::black()//retorna true si el color es negro y false si no
{
	return HIGH==digitalRead(pin);
}

float LightSensor::analogVoltage()
{
	return analogRead(pin);
}

float LightSensor::digitalVoltage()
{
	return digitalRead(pin);
}

//---------------------------------------Motor-----------------------------------------------
Motor::Motor(int pin1, int pin2, char side)/*Constructor de la clase motor, como parámetros los pines a los que se le conecta(driver)(pin1, pin2)
											y la primera letra del lado en el que lo ponemos (side, que puede tener los valores 'R' y 'L')*/
{
	if('R'==side ||'L'==side)
	{
		if('R'==side)//Como as ruedas estarán en los lados opuestos del robot, ante la misma entrada se moverán al revés
					//(el forward del izquierdoes el backward del derecho, por ejemplo), por lo que hay que invertir uno
		{
			pin[0]=pin2;
			pin[1]=pin1;
		}
		else
		{
			pin[0]=pin1;
			pin[1]=pin2;
		}
		pinMode(pin[0], OUTPUT);
		pinMode(pin[1], OUTPUT);
	}
	
}

void Motor::forward()//Avanzar
{
	digitalWrite(pin[0], LOW);
	digitalWrite(pin[1], HIGH);
}

void Motor::backward()//Retroeder
{
	digitalWrite(pin[0], HIGH);
	digitalWrite(pin[1], LOW);
}

void Motor::stop()//parar
{
	digitalWrite(pin[0], LOW);
	digitalWrite(pin[1], LOW);
}