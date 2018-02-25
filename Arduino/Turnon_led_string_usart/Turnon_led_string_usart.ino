char str[50];
char str1[50]="turn on";
char str2[50]="turn off";
int i=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
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
  if(strcmp(str1,str))
  {
    digitalWrite(D4,LOW);
    i=0;
  }
  if(strcmp(str2,str))
  {
    digitalWrite(D4,HIGH);
    i=0;
  }
}
