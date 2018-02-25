char c;
void setup() {
  // put your setup code here, to run once:
  pinMode(D4,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(!Serial.available());/*available() return type is character*/
  
    c=Serial.read();
    delay(100);
  
  if(c=='a' || c=='A')
  {
    digitalWrite(D4,LOW);
    
  }
  if(c=='b' || c=='B')
  {
    digitalWrite(D4,HIGH);
  }
  
  
}
