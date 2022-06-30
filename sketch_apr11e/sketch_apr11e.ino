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
    switch(data)
    {
      case '1' : digitalWrite(13, HIGH);
             break; 
      case '2' : digitalWrite(12, HIGH);
             break; 
      case '3' : digitalWrite(11, HIGH);
             break;        
      case '4' : 
                for(int i = 0; i<10; i++)
                {
                  digitalWrite(13, HIGH);
                  delay(100);
                  digitalWrite(13, LOW);
                  delay(100);
                }
                break;
      case '5' : 
                for(int i = 0;i<10;i++)
                {
                digitalWrite(12, HIGH);
                delay(100);
                digitalWrite(12, LOW);
                delay(100);
                }
                break;

      case '6' :     
                for(int i = 0;i<10;i++)
                {
                digitalWrite(11, HIGH);
                delay(100);
                digitalWrite(11, LOW);
                delay(100);
                }   
                break;

      default : 
              digitalWrite(13, LOW);
              digitalWrite(12, LOW);
              digitalWrite(11, LOW);
              break;
      
     }





    
  }
}
