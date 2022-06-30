#include <SoftwareSerial.h>

#define RX 6
#define TX 7

SoftwareSerial soft_Serial(RX,TX);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //TX 6,RX 7
  

}

void loop() {
  // put your main code here, to run repeatedly:
  if(soft_Serial.available()> 0)
  {
    int data = soft_Serial.read();
    
    
  }

}
