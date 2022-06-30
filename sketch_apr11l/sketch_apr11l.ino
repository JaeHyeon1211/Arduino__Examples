const int duration = 300;
unsigned long pre_time = 0;
unsigned long cur_time = 0;

volatile byte state = HIGH;
void isr()
{
  cur_time = millis();
  if(cur_time - pre_time >= duration)
  {
    Serial.println("인터럽트 발생");
    pre_time = cur_time;
    digitalWrite(13, state);
  state = !state;
  }
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  attachInterrupt(0, isr, RISING);
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
