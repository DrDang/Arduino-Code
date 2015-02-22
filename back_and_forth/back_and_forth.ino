#include<math.h>


int dirpin = 8;
int steppin = 7;
int enable = 9;

void setup() 
{
pinMode(dirpin, OUTPUT);
pinMode(steppin, OUTPUT);
}

void loop()
{

  int i;
  
  digitalWrite(dirpin, HIGH);    // sets direction
  delay(1000);

  for (i = 0; i<1000; i++)       // 800 microsteps is one revolution; 4 micro step is one step
  {
    digitalWrite(steppin, LOW);  // This LOW to HIGH change is what creates the
    digitalWrite(steppin, HIGH); // rising edge so that the driver knows to when to step.
    delayMicroseconds(500);      
  }                              
  
  digitalWrite(dirpin, LOW);    // sets direction
  delay(1000);

  for (i = 0; i<1000; i++)       // 800 microsteps is one revolution; 4 micro step is one step
  {
    digitalWrite(steppin, LOW);  // This LOW to HIGH change is what creates the
    digitalWrite(steppin, HIGH); // rising edge so that the driver knows to when to step.
    delayMicroseconds(500);      
  }  

}
