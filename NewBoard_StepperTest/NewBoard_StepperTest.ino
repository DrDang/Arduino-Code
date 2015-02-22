#include<math.h>


int dirpin = 8;
int steppin = 7;
int enable = 9;
float input = 6; // input in cm  CHANGE THIS LINE TO CHANGE DESIRED DISPLACEMENT
float required_steps;

void setup() 
{
pinMode(dirpin, OUTPUT);
pinMode(steppin, OUTPUT);
pinMode(enable, OUTPUT);
Serial.begin(9600);
}

void loop()
{

  int i;

  input *= 0.393701;                  // converts cm to inches
  Serial.print("input in inches: ");  
  Serial.print(input);                
  Serial.print("\n");
  
  required_steps = input/0.0003125;      // converts inches to steps
  Serial.print("Converted to steps before truncating: ");
  Serial.print(required_steps);
  Serial.print("\n");
  
  required_steps = floor(required_steps); // truncate
  Serial.print("After truncating: ");
  Serial.print(required_steps);
  Serial.print("\n");
  
  required_steps = required_steps * 4;   // scaling for 1/4 microstep
  Serial.print("multiplied by 4: ");
  Serial.print(required_steps);
  Serial.print("\n");
  
  digitalWrite(dirpin, HIGH);    // sets direction
  delay(1000);

  for (i = 0; i<required_steps; i++)       // 800 microsteps is one revolution; 4 micro step is one step
  {
    digitalWrite(steppin, LOW);  // This LOW to HIGH change is what creates the
    digitalWrite(steppin, HIGH); // rising edge so that the driver knows to when to step.
    delayMicroseconds(500);      
  }                              
  digitalWrite(enable, HIGH);
  delay(120000); // holds the Serial Monitor for 2 minutes before refreshing
}
