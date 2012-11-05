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
