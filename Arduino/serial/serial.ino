char ch;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  while(Serial.available())
  {
    ch=Serial.read();
    Serial.print(ch);
    Serial.print('\n');
    delay(1000);
  }
  // put your main code here, to run repeatedly:
  
}
