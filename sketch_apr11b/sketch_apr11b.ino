#define RED 11
void setup() {
  // put your setup code here, to run once:
    pinMode (13, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
    for(int i = 0; i<255;i++)
    {
      analogWrite(RED,i);
      delay(20);
     }
      for(int i=255; i>0;i--)
      {
        analogWrite(RED,i);
        delay(20);
      }
    
}
