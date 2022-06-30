void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)
  {
    int data = Serial.read();
    if(data == '1')
    {
      digitalWrite(13, HIGH);
    }
    else if(data =='2')
    {
      for(int i = 0; i<10; i++)
      {
        digitalWrite(13, HIGH);
        delay(500);
        digitalWrite(13, LOW);
        delay(500);
      }
    }
    else if (data == '3')
    {
      for(int i = 0;i<20;i++)
      {
      digitalWrite(12, HIGH);
      delay(400);
      digitalWrite(12, LOW);
      delay(200);
      }
    }
    else if (data == '4')
    {
      for(int i = 0;i<20;i++)
      {
      digitalWrite(11, HIGH);
      delay(400);
      digitalWrite(11, LOW);
      delay(200);
      }
    }
    else 
    digitalWrite(13, LOW);

    
    Serial.println(data);
    
    
    }
  //Serial.println("hello World");
  //delay(500);

}
