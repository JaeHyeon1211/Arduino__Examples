#include <Servo.h>
Servo myServo;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(11);
  pinMode(A0, INPUT);
  Serial.begin(9600);

}

void loop() {
  //int val = map(analogWrite(), 0, 255, 0 , 180);
  int val = analogRead(A0);
  
  int analog_out = map(val, 0, 1023, 0, 180);
  myServo.write(analog_out);
  Serial.print(val);
  delay(10);
  Serial.print("\t");
  Serial.println(analog_out);
  
//  for(int i = 0; i< 180; i++)
//  {
//    myServo.write(i);
//    delay(10);
//  }
  
}
