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
int idx = 0;
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
  if(dis <20)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    send_pa("dison");
  }
  // Serial.println(dis);
}
void send_pa(const char*val)
{
  soft_Serial.println(val);
}

void setup() {
  Serial.begin(9600);
  soft_Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(soundSensor, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  SPI.begin();
  mfrc.PCD_Init();
  lcd.init(); 
  lcd.backlight();
}

void loop() {
  if(state == true)
  {
//초음파 거리 측정
  delay(200);
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
          digitalWrite(2, LOW);
          digitalWrite(3, LOW);
          digitalWrite(4, LOW);
        }
  }
 

  //사운드 센서 측정  
  //Serial.println(analogRead(soundSensor));
   if(analogRead(soundSensor) >= threshold)
   {
    send_pa("soundon");
   }
  
    
  }

   //RFID
   if(!mfrc.PICC_IsNewCardPresent())
    return;
    if(!mfrc.PICC_ReadCardSerial())
    return;
    
    if(mfrc.uid.uidByte[0] == 227 && mfrc.uid.uidByte[1] == 212 &&
      mfrc.uid.uidByte[2] == 27 && mfrc.uid.uidByte[3] == 12)
          { 
          state = !state;
          if(state == true)
          {
          Serial.println("Sleep Mode ON");
          delay(100);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Sleep_Mode ON");
          send_pa("Sleep_Mode ON");

          }
          else
          {
          Serial.println("Sleep Mode OFF");
          delay(100);
          lcd.setCursor(0,0);
          lcd.print("Sleep_Mode OFF");

          digitalWrite(2, LOW);
          digitalWrite(3, LOW);
          digitalWrite(4, LOW);
          send_pa("alloff");
          send_pa("Sleep_Mode OFF");
          
          }
          }

        else
           {
           Serial.println("denied");
           delay(500);
           }
 
  
}
