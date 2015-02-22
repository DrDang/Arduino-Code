/**
Christopher Dang
Jan 17, 2015

This program is meant for the Position Control Testing and Verification experiment.  
The user sets how many steps in any direction and measures the displacement via an outside
tool.  This measured displacement is then compared against the theoretical displacement.

**/
#include<math.h>

// CONSTANTS
int dirpin = 8;
int steppin = 7;
int enable = 9;
int trigger = 6;

float required_steps = 2520; // CHANGE THIS LINE TO CHANGE DESIRED STEPS
int inwards = LOW;   
int outwards = HIGH; 

void setup() 
{
pinMode(dirpin, OUTPUT);
pinMode(steppin, OUTPUT);
pinMode(enable, OUTPUT);
Serial.begin(9600);
delay(5000); // delay 5 secs
}

void loop()
{
  int i;
 
  Serial.print("Converted to steps before truncating: ");
  Serial.print(required_steps);
  Serial.print("\n");
  
  required_steps = floor(required_steps); // truncate
  Serial.print("After truncating: ");
  Serial.print(required_steps);
  Serial.print("\n");
  
  required_steps = required_steps * 4;   // scaling for 1/4 microstep.  This is because
  Serial.print("multiplied by 4: ");     // By default, because the driver's pins M0 & M1
  Serial.print(required_steps);          // are float and HI respectively, hence 1/4 step
  Serial.print("\n");                    // mode.
  
  digitalWrite(dirpin, outwards);        // sets direction; set to either 'inwards' or 'outwards'
  delay(1000);

  for (i = 0; i<required_steps; i++)     // 800 microsteps is one revolution; 4 micro step is one step
  {
    digitalWrite(steppin, LOW);  // This LOW to HIGH change is what creates the
    digitalWrite(steppin, HIGH); // rising edge so that the driver knows to when to step.
    delayMicroseconds(500);      
  }                              
  digitalWrite(enable, HIGH);   // Turns off enable so motor doesn't stall
  delay(120000); // holds the Serial Monitor for 2 minutes before refreshing
}
