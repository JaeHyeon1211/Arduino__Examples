#include <IRremote.hpp>
#define IR_1 0xFF30CF
#define IR_2 0xFF18E7
int RECV_PIN = 8;
int led = 7;
IRrecv ir(RECV_PIN);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ir.enableIRIn();
  pinMode(7, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(ir.decode(&results))
  {
    Serial.println(results.value, HEX);
    //results가 리모콘 값을 저장하고 있음  
    switch(results.value)
    {
    case IR_1 : digitalWrite(7, HIGH);
                break;
    case IR_2 : digitalWrite(7, LOW);
                break;
    }
    ir.resume();//적외선값 다음 값
  }
  delay(100);
}
