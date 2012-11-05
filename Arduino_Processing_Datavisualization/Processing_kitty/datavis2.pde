/*----------------------

Visualization of Motion Sensor Data
Wenwen Li
November 1,2012

Be patient.
As you move
the  kitty will hide itself.

*/

import processing.serial.*;

Serial port;


PImage cat;
float y=210;
int displayArduinoVal;

void setup(){
size(500,500);
cat = loadImage("cat.png");
String arduinoPort = Serial.list()[0];
port = new Serial(this, arduinoPort,9600);
smooth();

}

void draw(){
 background(255); 

 if(port.available()>=0){
   displayArduinoVal = port.read(); 
 if(displayArduinoVal == 0){
 
 
      if(y>50){ 
      y=y-1;
        }
      if(y<=50){
      y=50;
      }
        image(cat,0,y);
 }
 
 if(displayArduinoVal == 1){
    y=210;}  
   image(cat,0,y);
 }
 
  println(displayArduinoVal);
}
  

