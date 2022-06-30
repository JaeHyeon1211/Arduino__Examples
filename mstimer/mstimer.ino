#include <MsTimer2.h>

#include <SPI.h>

#include <deprecated.h>

#include <require_cpp11.h>

#include <SoftwareSerial.h>

#define RX 5
#define TX 6
#define RST_PIN 9
#define SS_PIN 10

int trig = 8;
int echo = 7;
int soundSensor = A0;
int threshold = 400;
int data;
SoftwareSerial soft_Serial(RX,TX);

void dis_ledon(int dis) //초음파 거리센서 함수
{
  delay(10);
  if(dis <20)
  {
    digitalWrite(4, HIGH);
  }
   Serial.println(dis);
}

void isr()
{
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  int dis = pulseIn(echo, HIGH)* 340/2/10000;
  dis_ledon(dis);
  
}

void setup() {
  Serial.begin(9600);
  soft_Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(soundSensor, INPUT);
  
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  SPI.begin();
  MsTimer2 :: set(500, isr);
  MsTimer2 :: start();

}

void loop() {            
            
        
        if(soft_Serial.available()>0)
        {
          data = soft_Serial.read();
          if (data == '1')
          {
            //사운드 센서 측정  
             //Serial.println(analogRead(soundSensor));
             if(analogRead(soundSensor) >= threshold)
              {
              digitalWrite(3, HIGH);//부저
              digitalWrite(4, HIGH);//LED
              }
            
            }

            }

            if (data == '2')
            {
              digitalWrite(3, LOW);
              //digitalWrite(4, LOW);
            }
          }
          
      
        
        
