#include <MsTimer2.h>

#include <SPI.h>

#include <deprecated.h>

#include <require_cpp11.h>

#include <SoftwareSerial.h>
#define RX 5
#define TX 6
SoftwareSerial soft_Serial(RX,TX);

int trig = 8;
int echo = 7;
int soundSensor = A0;
int threshold = 65;
int data;
int a;
int b;

void dis_ledon(int dis){ 
  delay(10);
  if(dis <12){
    digitalWrite(4, HIGH);
    b = 1;
  }
  else{
    digitalWrite(4, LOW);
    b = 0;
  }
}
void isr(){
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  int dis = pulseIn(echo, HIGH)* 340/2/10000;
  dis_ledon(dis);
 }

void setup() {
  MsTimer2 :: set(300, isr);
  MsTimer2 :: start();
  Serial.begin(9600);
  soft_Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(soundSensor, INPUT);
  
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  SPI.begin();
  

}

void loop() {      
        
        if(soft_Serial.available()>0){
          data = soft_Serial.read();
          if (data == '1'){
             Serial.println(analogRead(soundSensor));
             if(analogRead(soundSensor) >= threshold){
              digitalWrite(3, HIGH);//부저
              digitalWrite(4, HIGH);//LED
              a = 1;
              }
            }
            }
            if (data == '2'){
              digitalWrite(3, LOW);
              a = 0;
            }

     if(a==NULL) a= 0;
     
     String str = (String)a +"#"+(String)b;
     soft_Serial.print(str);
     
     delay(400);
     
     Serial.println(str);
     
            
          }
