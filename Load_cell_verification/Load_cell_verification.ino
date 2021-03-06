/**
Christopher Dang
February 9, 2015

The purpose of this program is to test and verify the load cell operation for use in the PID controller.

It will do a couple of tests:
1) see how to load cell changes per step
2) see how the load cell changes per revolution
3) verify the load cell against a force sensor

**/
#include<math.h>             // to do mathy things

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////  CONSTANTS  /////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int dirpin = 8;                // to control direction
int steppin = 7;               // to controls the step
int enable = 9;                // to turn our actuator off or on
int rpm_control_delay = 1100;  // delay between steps to control the motor control speed
int inwards = LOW;             // sets our direction
int outwards = HIGH;           // sets our direction
double Vcc;
unsigned int ADCValue;
double Voltage;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////  FUNCTIONS  /////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


long readVcc() {
  long result;
  // Read 1.1V reference against AVcc
  ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
  delay(2); // Wait for Vref to settle
  ADCSRA |= _BV(ADSC); // Convert
  while (bit_is_set(ADCSRA,ADSC));
  result = ADCL;
  result |= ADCH<<8;
  result = 1125300L / result; // Back-calculate AVcc in mV
  return result;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////  SETUP  /////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() 
{
pinMode(dirpin, OUTPUT);      // sets up our GPIO pins
pinMode(steppin, OUTPUT);     // sets up our GPIO pins
pinMode(enable, OUTPUT);      // sets up our GPIO pins
digitalWrite(dirpin, outwards); // sets direction
analogReference(INTERNAL);
Serial.begin(9600);           // begin our serial comm for the serial monitor
delay(5000);                  // delay 5 secs so we can make adjustments to the physical motor before it runs
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////  LOOP  ///////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop()
{/**
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
  **/
  digitalWrite(enable, HIGH);    // Turns off enable so motor doesn't stall
  //delay(3000);                   // delay 5 secs so that we can record the speed
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////  ADC READING  ///////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
  
  
  Vcc = readVcc()/1000.0;
  ADCValue = analogRead(0);
  Voltage = (ADCValue/1023.0)*1.1;
  Serial.println(Voltage);
  delay(1000);
     
}
