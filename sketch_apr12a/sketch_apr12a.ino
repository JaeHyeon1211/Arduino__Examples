void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(A1);
  int analog_Out = map(val, 80, 1000, 255, 0);
  Serial.print(val);
  Serial.print("\t");
  Serial.println(analog_Out);
  delay(10);
}
