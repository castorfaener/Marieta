#include <Wire.h>

const int RedLedPin = 6;
const int GreenLedPin = 5;
const int BlueLedPin = 3;
const int FanPin = 10;

const int AM2302Pin = 8;
const int DoorSensor = 4;



void setup()
{
	pinMode(RedLedPin, OUTPUT);
	pinMode(GreenLedPin, OUTPUT);
	pinMode(BlueLedPin, OUTPUT);
	pinMode(FanPin, OUTPUT);

	pinMode(DoorSensor, INPUT);
	pinMode(AM2302Pin, INPUT);

}


void loop()
{


}

// % Fan control 0-100

void Fan(int val)
{
	val = map(val, 0, 100, 0, 255);
	digitalWrite(FanPin, val);
}

// RGB control -->  0:Off 	1:Red 	2:Green 	3:Blue 	4:Yellow	5:Purple 	6:White

void RGB(int val)
{
	int RedVal = 0;
	int GreenVal = 0;
	int BlueVal = 0;

	switch(val)
	{
		case 0:
		RedVal = 0;
		GreenVal = 0;
		BlueVal = 0;
		break;

		case 1:
		RedVal = 255;
		GreenVal = 0;
		BlueVal = 0;
		break;

		case 2:
		RedVal = 0;
		GreenVal = 255;
		BlueVal = 0;
		break;

		case 3:
		RedVal = 0;
		GreenVal = 0;
		BlueVal = 255;
		break;

		case 4:
		RedVal = 255;
		GreenVal = 255;
		BlueVal = 0;
		break;

		case 5:
		RedVal = 255;
		GreenVal = 0;
		BlueVal = 255;
		break;

		case 6:
		RedVal = 255;
		GreenVal = 255;
		BlueVal = 255;
		break;
	}

	digitalWrite(RedLedPin, RedVal);
	digitalWrite(GreenLedPin, GreenVal);
	digitalWrite(BlueLedPin, BlueVal);
}