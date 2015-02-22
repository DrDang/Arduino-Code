/**
Christopher Dang
February 6, 2015

The purpose of this program is to test and verify the speed control of our motor for use in the PID controller.
We need to know the our motor's speed limits so that our control stays within them. This will allow us to
consciously avoid windup as well as insure that our motor moves when we expect it to.


**/
#include<math.h>             // to do mathy things

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////  CONSTANTS  /////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int dirpin = 8;                // to control direction
int steppin = 7;               // to controls the step
int enable = 9;                // to turn our actuator off or on
int rpm_control_delay = 1100; // delay between steps to control the motor control speed
int inwards = LOW;             // sets our direction
int outwards = HIGH;           // sets our direction

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////  SETUP  /////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() 
{
pinMode(dirpin, OUTPUT);      // sets up our GPIO pins
pinMode(steppin, OUTPUT);     // sets up our GPIO pins
pinMode(enable, OUTPUT);      // sets up our GPIO pins
digitalWrite(dirpin, outwards); // sets direction
Serial.begin(9600);           // begin our serial comm for the serial monitor
delay(5000);                  // delay 5 secs so we can make adjustments to the physical motor before it runs
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////  LOOP  ///////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop()
{
  int i;
  
  
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////  MOVEMENT 1  /////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
  
  Serial.print("starting movement 1: ");
  Serial.println(micros());
  for (i = 0; i<1600; i++)       // 800 microsteps is one revolution; 4 micro step is one step and...
  {                              // 1600 microsteps means 2 revolutions.
    digitalWrite(steppin, LOW);  // Create the LO to HI edge that defines the step
    digitalWrite(steppin, HIGH); // rising edge so that the driver knows to when to step.
    delayMicroseconds(rpm_control_delay);      // The delay between each edge determines speed  
  }     
  
  Serial.println(micros());                       // get our timing  millis();
  digitalWrite(dirpin, inwards); // flips direction so that coupler doesn't travel too far
  digitalWrite(enable, HIGH);    // Turns off enable so motor doesn't stall
  delay(3000);                   // delay 5 secs so that we can record the speed        

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////  MOVEMENT 2  /////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


  Serial.print("starting movement 2: ");
  Serial.println(micros());
  for (i = 0; i<1600; i++)       // 800 microsteps is one revolution; 4 micro step is one step
  {                              // 1600 microsteps means 2 revolutions.
    digitalWrite(steppin, LOW);  // Create the LO to HI edge that defines the step
    digitalWrite(steppin, HIGH); // rising edge so that the driver knows to when to step.
    delayMicroseconds(rpm_control_delay);      // The delay between each edge determines speed
  }

  Serial.println(micros());  
  digitalWrite(dirpin, outwards); // sets direction
  digitalWrite(enable, HIGH);     // Turns off enable so motor doesn't stall
  delay(3000);                    // delay 5 secs so that we can record the speed   
  

}
