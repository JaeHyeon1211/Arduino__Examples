#include <MsTimer2.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include <SPI.h>

#include <deprecated.h>
#include <MFRC522.h>
#include <MFRC522Extended.h>
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
boolean state = false;

SoftwareSerial soft_Serial(RX,TX);
MFRC522 mfrc(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd (0x27, 16 ,2);

void dis_ledon(int dis) //초음파 거리센서 함수
{
  delay(100);
  if(dis <20)
  {
    digitalWrite(4, HIGH);
  }
   Serial.println(dis);
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
  mfrc.PCD_Init();
  lcd.init(); 
  lcd.backlight();
//
//  MsTimer2 :: set(1000, isr);
//  MsTimer2 :: start();
}

void loop() {
    if(state == true)
        {
        //초음파 거리 측정
        digitalWrite(trig, HIGH);
        delayMicroseconds(10);
        digitalWrite(trig, LOW);
        int dis = pulseIn(echo, HIGH)* 340/2/10000;
        
        dis_ledon(dis);

        if(soft_Serial.available()> 0)
        {
          int data = soft_Serial.read();
            if ( data == '3')
              {
                digitalWrite(3, LOW);
                digitalWrite(4, LOW);
              }
        }
          //사운드 센서 측정  
          Serial.println(analogRead(soundSensor));
         if(analogRead(soundSensor) >= threshold)
          {
            
          digitalWrite(3, HIGH);//부저
          digitalWrite(4, HIGH);//LED
          }
    
        }
        
     else
       {
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
       }

   //RFID
   if(!mfrc.PICC_IsNewCardPresent())
    return;
   if(!mfrc.PICC_ReadCardSerial())
    return;
     if(mfrc.uid.uidByte[0] == 227 && mfrc.uid.uidByte[1] == 212 &&
        mfrc.uid.uidByte[2] == 27 && mfrc.uid.uidByte[3] == 12)
        {
        delay(500);
        state = !state;
          if(state == true)
            Serial.println("Open");
              //내부인터럽트 필요 1초기다리는 시간 필요
              
          else
            Serial.println("close");
          }
     else
        {
        Serial.println("denied"); 
        }

}
