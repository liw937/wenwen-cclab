// Maurice Ribble 
// 8-30-2009
// http://www.glacialwanderer.com/hobbyrobotics
// Used Arduino 0017
// This is a simple test app for some cheap RF transmitter and receiver hardware.
// RF Transmitter: http://www.sparkfun.com/commerce/product_info.php?products_id=8945
// RF Receiver: http://www.sparkfun.com/commerce/product_info.php?products_id=8948

// This says whether you are building the transmistor or reciever.
// Only one of these should be defined.



#define TRANSMITTER
//#define RECEIVER

// Arduino digital pins
#define BUTTON_PIN  2
#define ledPin     13
#define speakerOut 9

byte names[] = {'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C'};  
int tones[] = {1915, 1700, 1519, 1432, 1275, 1136, 1014, 956};
byte melody[] = "2d2a1f2c2d2a2d2c2f2d2a2c2d2a1f2c2d2a2a2g2p8p8p8p";
// count length: 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0
//                                10                  20                  30
int count = 0;
int count2 = 0;
int count3 = 0;
int MAX_COUNT = 24;
int statePin = LOW;

// Button hardware is setup so the button goes LOW when pressed
#define BUTTON_PRESSED LOW
#define BUTTON_NOT_PRESSED HIGH

void setup()
{
  pinMode(BUTTON_PIN, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

 
  

  Serial.begin(1200);  // Hardware supports up to 2400, but 1200 gives longer range
}

#ifdef TRANSMITTER
void loop()
{
//  static int prev_button = BUTTON_NOT_PRESSED;  // Previous button press value
//  int        cur_button;                        // Current button press value
//
//  cur_button = digitalRead(BUTTON_PIN);
//
//
//  if ((prev_button == BUTTON_NOT_PRESSED) && (cur_button == BUTTON_PRESSED))
//  {
//    writeUInt(271); // Put any number you want to send here (71 is just a test)
//  }
// 
//  delay(50); // Debounce button
//  prev_button = cur_button;

static int prev_button = BUTTON_NOT_PRESSED;
 int        cur_button; 
cur_button = digitalRead(BUTTON_PIN);
if((prev_button == BUTTON_PRESSED) && (cur_button == BUTTON_NOT_PRESSED))
{
  writeUInt(271);
}
delay(50);
prev_button = cur_button;

}
#endif //TRANSMITTER

#ifdef RECEIVER
void loop()
{
//  boolean light_led = false;
//
//  if (readUInt(true) == 271) // Check to see if we got the 71 test number
//  {
//    light_led = true;
//  }
//  
//  if (light_led)
//  {
//    digitalWrite(LED_PIN, HIGH);
//    delay(1000);
//    digitalWrite(LED_PIN, LOW);
//  }
  
  //-------------------speaker---------------------------  
boolean play_speaker = false;

  if (readUInt(true) == 271) // Check to see if we got the 71 test number
  {
    play_speaker = true;
  }
  
  if (play_speaker)
{  
//  { analogWrite(speakerOut, 0);     
  for (count = 0; count < MAX_COUNT; count++) {
    statePin = !statePin;
    digitalWrite(ledPin, statePin);
    for (count3 = 0; count3 <= (melody[count*2] - 48) * 30; count3++) {
      for (count2=0;count2<8;count2++) {
        if (names[count2] == melody[count*2 + 1]) {       
          analogWrite(speakerOut,500);
          delayMicroseconds(tones[count2]);
          analogWrite(speakerOut, 0);
          delayMicroseconds(tones[count2]);
        } 
        if (melody[count*2 + 1] == 'p') {
          // make a pause of a certain size
          analogWrite(speakerOut, 0);
          delayMicroseconds(500);
        }
      }
    }
  }
}  
   
//-----------------------------------------------------
  }  

#endif //RECEIVER


