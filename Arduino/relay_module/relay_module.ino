#include<string.h>
//String on1="turn on";
//String off="turn off";

char on1[20]="turn on";
char off[20]="turn off";
char str[20];
int i=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(D6,INPUT);//pin for relay
  pinMode(D4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(!Serial.available());
  while(Serial.read()!='\n')
  {
  str[i]=Serial.read();
  i++;
  }
  if(strcmp(on1,str)==0)
  {
    digitalWrite(D6,HIGH);
    digitalWrite(D4,HIGH);
    i=0;
  }
  if(strcmp(off,str)==0)
  {
    digitalWrite(D6,LOW);
    digitalWrite(D4,LOW);
    i=0;
  }
}
