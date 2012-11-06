/*----------------------

Visualization of Motion Sensor Data
Wenwen Li
November 1,2012

Be patient.
As you move
the  kitty will hide itself.

*/

int motionPin=2;
int motionVal;

void setup(){
Serial.begin(9600);
pinMode(motionPin,INPUT);
}

void loop(){
int motionVal = digitalRead(motionPin);
Serial.write(motionVal);
delay(50);
}
