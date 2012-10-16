#define LED1 9
#define LED2 10
#define LED3 11
int i=0;
int j=0;
int k=0;

void setup(){
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);

}

void loop(){
for(i=0;i<255;i++){  
analogWrite(LED1,i);
delay(5);}
for(i=255;i>0;i--){
analogWrite(LED1,i);
delay(5);}
delay(1000);

for(j=0;j<150;j++){  
analogWrite(LED2,j);
delay(10);}
for(j=150;j>0;j--){  
analogWrite(LED2,j);
delay(10);
}

for(k=0;k<50;k++){  
analogWrite(LED3,k);
delay(15);}
for(k=50;k>0;k--){  
analogWrite(LED3,k);
delay(15);
}
}
