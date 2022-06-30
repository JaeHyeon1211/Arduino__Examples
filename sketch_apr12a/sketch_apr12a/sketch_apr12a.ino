#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd (0x27, 16 ,2);
void setup() {
  lcd.init(); //초기화
  lcd.backlight();
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analog_In = analogRead(A0);
  int cds = map(analog_In, 0, 1023, 255, 0);
  String val = (String)cds;
  Serial.println(cds);
  delay(1000);
  lcd.clear();
  lcd.setCursor(1,0);//16x2
  lcd.print("JAE HYEON");
  lcd.setCursor(0,1);//16x2
  lcd.print("CDS:");
  if(cds <220){
    lcd.setCursor(4,1);
    while(()>0) {
      lcd.write('val');
    }
    
    lcd.setCursor(8,1);
    lcd.print("Led ON");
  }
  else
  {
    lcd.setCursor(4,1);
    lcd.print(cds);
    lcd.setCursor(8,1);
    lcd.print("Led OFF");
  }
}
