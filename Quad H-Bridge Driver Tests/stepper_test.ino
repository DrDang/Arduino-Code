/**
Here is code to test our stepper motor
**/

int myA1 = 8; // Define pin 7 as enable 1,2
int myA2 = 9; // Define pin 8 as enable 3,4
int myB1 = 10;
int myB2 = 11;

void setup() {
  pinMode(myA1, OUTPUT);
  pinMode(myA2, OUTPUT);
  pinMode(myB1, OUTPUT);
  pinMode(myB2, OUTPUT);  
}

void loop(){
		digitalWrite(myA1, HIGH);
		digitalWrite(myA2, HIGH);
        digitalWrite(myB1, LOW);
		digitalWrite(myB2, LOW);
		delay(500);
		digitalWrite(myA1, LOW);
		digitalWrite(myA2, HIGH);
        digitalWrite(myB1, HIGH);
		digitalWrite(myB2, LOW);
		delay(500);
		digitalWrite(myA1, LOW);
		digitalWrite(myA2, LOW);
        digitalWrite(myB1, HIGH);
		digitalWrite(myB2, HIGH);
		delay(500);
		digitalWrite(myA1, HIGH);
		digitalWrite(myA2, LOW);
        digitalWrite(myB1, LOW);
		digitalWrite(myB2, HIGH);
		delay(500);
} 
