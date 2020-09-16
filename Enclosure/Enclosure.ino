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

void Fan(int val)
{
	val = map(val, 0, 100, 0, 255);
	digitalWrite(FanPin, val);
}