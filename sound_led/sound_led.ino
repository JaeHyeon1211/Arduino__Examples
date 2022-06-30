int soundSensor = A0;
int led[3] = {11, 12, 13};
int threshold = 400;
int count =0; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(soundSensor, INPUT);
  for(int i = 0; i < 3; i++)
  {
    pinMode(led[i], OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(soundSensor));
  if( analogRead(soundSensor) >= threshold)
  {
    for(int i = 0; i<3; i++)
    {
      if(i == count)
      digitalWrite(led[i], HIGH);
      else
      digitalWrite(led[i], LOW);
    }
    count = (count < 3) ? count + 1 : 0;
    delay(200);
  }
  else
  delay(1);

}
