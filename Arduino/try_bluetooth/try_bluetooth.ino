
String str="";
//int i=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  digitalWrite(8,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available())
  {
    delay(10);
    char c=Serial.read();
    if(c=='#')
    {
      break;
      }
    str+=c;
  }
  if(str.length()>0)
  {
    //Serial.print(str);
    if(str=="on")
    {
      digitalWrite(8,HIGH);
    }
    if(str=="of")
    {
      digitalWrite(8,LOW);
    }
  }
    str="";
  }
