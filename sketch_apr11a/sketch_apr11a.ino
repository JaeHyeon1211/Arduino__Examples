#define RED 13
#define GREEN 12
#define BLUE 11



void setup() {
  // put your setup code here, to run once:

  pinMode (13, OUTPUT);
  pinMode (12, OUTPUT);
  pinMode (11, OUTPUT);
  
  

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  delay(300);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, LOW);
  delay(300);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN,HIGH );
  digitalWrite(BLUE, HIGH);
  delay(300);

}
