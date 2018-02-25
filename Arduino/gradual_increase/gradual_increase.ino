
void setup() {
  // put your setup code here, to run once:
pinMode(D4,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
 for(int i=1;i<=1023;i++)
 {
 analogWrite(D4,i);
 
 delay(10);
 
 }
}
