#include <SoftwareSerial.h>
SoftwareSerial ble(2,3); //TX, RX시리얼 코드 지정

String myStr= "";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ble.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(ble.available())
  {
    char mychar = ble.read();
    myStr += mychar;
    delay(5);
  }
  if(!myStr.equals(""))
  {
    Serial.println("input value : " + myStr);
    if(myStr =="led on\r\n")
      digitalWrite(13, HIGH);
    else if (myStr == "led off\r\n")
      digitalWrite(13, LOW);
    else
      {
        digitalWrite(13, HIGH);
        delay(100);
        digitalWrite(13, LOW);
        delay(100);
        digitalWrite(13, HIGH);
        delay(100);
        digitalWrite(13, LOW);
        delay(100);
      }
   
    myStr="";
 
    }
}
