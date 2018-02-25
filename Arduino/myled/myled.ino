
void setup() {
  Serial.read(9600);
pinMode(8,OUTPUT);
}

void loop() {
  
  analogWrite(8,100);
  delay(10000);
  analogWrite(8,500);
  delay(10000);

  analogWrite(8,1023);
  delay(10000);
}
