#include<LiquidCrystal.h>
LiquidCrystal lcd(D0,D1,D2,D3,D4,D5);
void setup() {
  // put your setup code here, to run once:
 lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
 lcd.setCursor(0,0);
 lcd.print('a');
 delay(200);
 lcd.print("hello world");
 delay(200);
 
}
