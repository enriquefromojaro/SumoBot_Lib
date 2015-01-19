
#include "SumoBot_Lib.h"
#include "arduino.h"
#define COEFICIENTE 16746.73
#define EXPONENTE -1.2134


///-----------------------------------SumoBot------------------------------------------------------------------------------

//---Builder

SumoBot::SumoBot()
{
	//Asignamos los pines como indica el manual
	pinDist=A3;
	pinLight_R=A0;
	pinLight_L=A1;
	pinMotor_R1=5;
	pinMotor_R2=6;
	pinMotor_L1=6;
	pinMotor_L2=7;
	pinRed=2;
	pinGreen=3;
	pinBlue=4;
	
	//Llamamos a losconstructores de los componentes para inicializarlos

}
float SumoBot::getDistance(float voltage)//Retorna la distancia en centímetros (cm) según la formula del SHARP en función del voltaje introducido
{
	return COEFICIENTE * float(pow(voltage,EXPONENTE));
}

//--------------------------------DistanceSensor-----------------------------------------------

DistanceSensor::DistanceSensor(int pinInput)//Constructor del Sensor de Distancia
{
	pin=pinInput;
	pinMode(pin, INPUT);
	coeficiente= COEFICIENTE;
	exponente= EXPONENTE;
}
float DistanceSensor::distance()//Retorna la distancia en centímetros (cm) según la formula del SHARP
{
	return coeficiente * float(pow(analogRead(pin),exponente));
}

float DistanceSensor::anRead()
{
	return analogRead(pin);
}

float DistanceSensor::digRead()
{
	return digitalRead(pin);
}

void DistanceSensor::setCoeficiente(float coef)
{
	coeficiente=coef;
}

void DistanceSensor::setExponente(float exp)
{
	exponente=exp;
}

float DistanceSensor::getCoeficiente()
{
	return coeficiente;
}

float DistanceSensor::getExponente()
{
	return exponente;
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

float LightSensor::anRead()
{
	return analogRead(pin);
}

float LightSensor::digRead()
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

void Motor::backward()//Retroceder
{
	digitalWrite(pin[0], HIGH);
	digitalWrite(pin[1], LOW);
}

void Motor::stop()//parar
{
	digitalWrite(pin[0], LOW);
	digitalWrite(pin[1], LOW);
}


//------------------------------------------Led------------------------------------------------------------------

//Builder
Led::Led(int red, int green, int blue)
{
	pinRed=red;
	pinGreen=green;
	pinBlue=blue;
	
	//Inicializamos los pines a salida
	pinMode(pinRed, OUTPUT);
	pinMode(pinGreen, OUTPUT);
	pinMode(pinBlue, OUTPUT);
}

//Method red---> Turns on the led with red color
void Led::red()
{
	//Ponemos todos los pines a LOW excepto el rojo (pinRed)
	digitalWrite(pinRed, LOW);
	digitalWrite(pinBlue, HIGH);
	digitalWrite(pinGreen, HIGH);
}

//Method blue---> Turns on the led with blue color
void Led::blue()
{
	//Ponemos todos los pines a LOW excepto el azul (pinBlue)
	digitalWrite(pinRed, HIGH);
	digitalWrite(pinBlue, LOW);
	digitalWrite(pinGreen, HIGH);
}

//Method green---> Turns on the led with green color
void Led::green()
{
	//Ponemos todos los pines a LOW excepto el verde (pinGreen)
	digitalWrite(pinRed, HIGH);
	digitalWrite(pinBlue, HIGH);
	digitalWrite(pinGreen, LOW);
}

//Method red---> Turns off the led
void Led::off()
{
	//Ponemos todos los pines a LOW
	digitalWrite(pinRed, HIGH);
	digitalWrite(pinBlue, HIGH);
	digitalWrite(pinGreen, HIGH);
}