int x;
int c=0;
void setup() {
  // put your setup code here, to run once:
 pinMode(D0,OUTPUT);
 pinMode(D1,OUTPUT);
 pinMode(D2,OUTPUT);
 pinMode(D4,OUTPUT);
 pinMode(D6,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  x=digitalRead(D6);
  if (x==HIGH)
  {
    while(x==HIGH)
    {
      x=digitalRead(D6);
    }
    c++;
  }
  if(c%2==1)
  {
    digitalWrite(D0,HIGH);
    digitalWrite(D1,HIGH);
    digitalWrite(D2,HIGH);
    digitalWrite(D4,LOW);
    
  }
  if(c%2==0)
  {
    digitalWrite(D0,LOW);
    digitalWrite(D1,LOW);
    digitalWrite(D2,LOW);
    digitalWrite(D4,HIGH);
  }
}
