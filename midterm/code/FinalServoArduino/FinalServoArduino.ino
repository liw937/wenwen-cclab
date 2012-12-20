
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.

// Range appears to be 0-171, and 600-2300 micros, 1350 midpoint


#include <Servo.h> 
 
//#define LED_PIN 13
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  Serial.begin(9600);

} 
 
 
void loop() 
{ 
  boolean update = false;
  while(Serial.available() > 0) {
    byte temp = Serial.read();
    if(temp == '.') {
      update = true;
      break;
    } else {
      pos *= 10; // shift the currently stored position
      pos += (temp - '0'); // Add the new digit;
    }
  }

  if(update && pos >= 0 && pos <= 180) {
    int temp = map(pos, 0, 250, 0, 2300); // Map degrees (0-250) to microseconds (0-2300)
    myservo.writeMicroseconds(temp);

    pos = 0;
    
 
  }
  // Warn on invalid data
  else if(update) {
    //Serial.print("Invalid position [");
    //Serial.print(pos, DEC);
    //Serial.println("]. Please enter a position between 0 and 180 degrees");
    pos = 0;
  }
}



