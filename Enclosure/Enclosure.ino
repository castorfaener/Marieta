#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int RedLedPin = 6;
const int GreenLedPin = 5;
const int BlueLedPin = 3;
const int FanPin = 10;

const int AM2302Pin = 8;
const int DoorSensor = 4;

const int EncCLK = 2;
const int EncDt = 12;
const int EncButton = 11;

volatile unsigned int EncoderPos = 0;


LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup()
{
	pinMode(RedLedPin, OUTPUT);
	pinMode(GreenLedPin, OUTPUT);
	pinMode(BlueLedPin, OUTPUT);
	pinMode(FanPin, OUTPUT);

	pinMode(DoorSensor, INPUT);
	pinMode(AM2302Pin, INPUT);

	attachInterrupt(0, Encoder, CHANGE);

	lcd.begin();
	lcd.backlight();

}

void Encoder()
{
	if (digitalRead(EncCLK) == digitalRead(EncDt))
	{
		EncoderPos++; 	//Sentido horario
	}
	else 
	{
		EncoderPos--;	//Sentido antihorario
	}
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

void Menu(int SubMenu)
{
	switch(SubMenu)
	{
		case 0:
		lcd.clear();
		lcd.setCursor(0 ,0);
		lcd.print("Temperatura 3D");
		lcd.setCursor(0,1);
		lcd.print("Humedad 3D");
		delay(10);
		break;

		case 1:
		lcd.clear();
		lcd.setCursor(0 ,0);
		lcd.print("Temperatura H");
		lcd.setCursor(0,1);
		lcd.print("Humedad H");
		delay(10);
		break;

	}
}