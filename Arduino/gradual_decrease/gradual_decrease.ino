void setup() {
  // put your setup code here, to run once:
 pinMode(D4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   for(int i=1023;i>0;i--)
   {
    analogWrite(D4,i);
    delay(100);
   }
}
