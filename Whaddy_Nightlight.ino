/*
  @@@@@@@@@@@@@@@@@@@@@@
  @@@@@@@@@@@@@@@@@@@@@@             @@@.    @@@    @@@.     @@@@    @@@@        @@@@@@@@@        @@@@@@@@@@@@@.     .@@@@@@@@@@@@@        @@@@@@@@@
  @@@@@%%@@@%%@@@%%@@@@@             @@@@    @@@    @@@@     @@@@    @@@@       @@@@@@@@@@        @@@@@@@@@@@@@@     @@@@@@@@@@@@@@        @@@@@@@@@
  @@@@@  @@@  @@@  @@@@@             @@@@    @@@    @@@@     @@@@    @@@@       @@@@   @@@@        @@@@@   @@@@@       @@@@@   @@@@       @@@@   @@@@
  @@@@@            @@@@@             @@@@   @@@@    @@@@     @@@@@@@@@@@@       @@@@   @@@@        @@@@@   @@@@@       @@@@@   @@@@       @@@@   @@@@
  @@@@@   @    @   @@@@@             @@@@   @@@@    @@@@     @@@@@@@@@@@@       @@@@@@@@@@@        @@@@@   @@@@@       @@@@@   @@@@       @@@@@@@@@@@
  @@@@@            @@@@@             @@@@###@@@@@##@@@@@     @@@@    @@@@      @@@@@@@@@@@@       #@@@@@###@@@@@     ##@@@@@###@@@@       @@@@@@@@@@@
  @@@@@@@@@@@@@@@@@@@@@@             @@@@@@@@@@@@@@@@@@@     @@@@    @@@@      @@@@    @@@@@      @@@@@@@@@@@@@@     @@@@@@@@@@@@@@      @@@@     @@@@
  @@@@@@@@@@@@@@@@@@@@@@

  Whaddy Nightlight, a nightlight in the shape of our mascot Whaddy! Fits on most phone charger in the EU

  Description:
  This project uses an Digital light sensor to measure the ambient light. When a certain light value is reached, the 2 SMD RGB leds will turn on and give your room a purple shine!

  Level of difficulty: Intermediate


  (c) 2020 Whadda, premium makers brand by Velleman
*/

// Include necessary libraries
#include <Arduino.h>
#include <hp_BH1750.h>  //for help look at: https://github.com/Starmbi/hp_BH1750/wiki
hp_BH1750 BH1750;       //create the sensor object
//////////////////////////////////////

//Define pins for the SMD RGB LEDs
int Pred = A1;
int Pgreen = A2;
int Pblue = A0;
////////////////////////////////////////

// Value to determe at wich value the LEDs should switch on
// The lower the value,the darker 
int Dark = 10;
/////////////////////////////////////////

//Variables to calculate the light intensity value
int Min = 1023;
int Max = 0;
unsigned long Sum = 0;
unsigned long Alux;
///////////////////////////////////////////

void setup()
{

  Serial.begin(9600);// Start Serial port with baudrate of 9600

  bool avail = BH1750.begin(BH1750_TO_GROUND);   // will be false no sensor found
  // use BH1750_TO_GROUND or BH1750_TO_VCC depending how you wired the address pin of the sensor.

  // BH1750.calibrateTiming();  //uncomment this line if you want to speed up your sensor
  BH1750.start();               //start the first measurement in setup
  
  // Set output pins
  pinMode(Pred, OUTPUT);
  pinMode(Pgreen, OUTPUT);
  pinMode(Pblue, OUTPUT);
  //////////////////////////////////////////////
}

void loop()
{
  AvarageLux();

  if (Alux < Dark) {      // When Avarage Lux measurement is lower then....
    setColor(210, 0, 210); // Set color to Purple (RGB)
  }
  else if (Alux > Dark) { // When Avarage Lux measurement is Higher then....
    setColor(0, 0, 0);    // STurn LEDs off
  }

}

void setColor(int red, int green, int blue)
{
  analogWrite(Pred, red);
  analogWrite(Pgreen, green);
  analogWrite(Pblue, blue);
}

//Function to calculate the avarege lux from 10 readings
void AvarageLux()
{
  for  (int i = 0; i < 10; i++)
  {
    float lux = BH1750.getLux();
    BH1750.start();
    Sum = Sum + lux;

    if (lux < Min)
      Min = lux;

    if (lux > Max)
      Max = lux;
  }
  Alux = (Sum / 10);
  Serial.print (" Average = ");
  Serial.println (Alux);

}
