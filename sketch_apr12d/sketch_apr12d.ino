int trig = 2;
int echo = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(7, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  int dis = pulseIn(echo, HIGH)* 340/2/10000;
  if(dis <20)
  {
      digitalWrite(7, HIGH);
      delay(dis*10);
      digitalWrite(7, LOW);
      delay(dis*10);
  
  }
  else if(dis>200)
  {
    dis = 0;
  }
  else
  {
    digitalWrite(7, LOW);
  }
    Serial.println(dis);
}
