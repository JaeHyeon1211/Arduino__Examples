#include <SoftwareSerial.h>

#define RX 6
#define TX 7


SoftwareSerial soft_Serial(RX,TX);
void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600); //TX RX 1 0
  soft_Serial.begin(9600); //TX 6,RX 7
  pinMode(13, OUTPUT);
  

}

void loop() {
  
  soft_Serial.print(1);
  digitalWrite(13, HIGH);
  delay (1000);
  digitalWrite(13, LOW);
  delay (1000);
  soft_Serial.print(2);
  delay(1000);
  digitalWrite(13, HIGH);
  delay (1000);
  digitalWrite(13, LOW);
  delay (1000);
  soft_Serial.print("ledon");
  digitalWrite(13, HIGH);
  delay(1000);
  soft_Serial.print("ledoff");
  digitalWrite(13, LOW);
  delay (1000);
  

}
