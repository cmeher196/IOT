/*when u press the  button then it shud glow till the max value if u havnt remove ur finger from it*/
int f=0;
int x;
int c=0,i=0,j=1023;
void run()
{
  
}
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
   if(x==HIGH)
   {
    while(x==HIGH )
    {
      ++i;
      --j;
      x=digitalRead(D6);
      analogWrite(D0,i);
      delay(10);
      analogWrite(D1,i);
      delay(10);
      analogWrite(D2,i);
      delay(10);
      analogWrite(D4,j);
      if(i>1023 && j<0)
      {
       digitalWrite(D0,HIGH);
      digitalWrite(D1,HIGH);
      digitalWrite(D2,HIGH);
      digitalWrite(D4,LOW);
      
      }
    }
    c++;
   }
 
   
   if( c%2!=0)
   {
      analogWrite(D0,0);
      analogWrite(D1,0);
      analogWrite(D2,0);
      analogWrite(D4,1024);
      i=0;
      
   }

  }

