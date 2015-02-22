/**
Here is code to test our stepper motor
**/

int A = 8; // Define pin 7 as enable 1,2
int B = 9; // Define pin 8 as enable 3,4

for (i = 0;i<5;i++){
	digitalWrite(A, HIGH);
	digitalWrite(B, HIGH);
	delay(100);
	digitalWrite(A, LOW);
	digitalWrite(B, HIGH);
	delay(100);
	digitalWrite(A, LOW);
	digitalWrite(B, LOW);
	delay(100);
	digitalWrite(A, HIGH);
	digitalWrite(B, LOW);
	delay(100);
} 