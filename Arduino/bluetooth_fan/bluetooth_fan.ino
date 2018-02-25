String voice="";

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(7,OUTPUT);
 digitalWrite(7,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available())
  {
    delay(50);
    char c=Serial.read();
    if(c=='#')
    {
      break;
    }
    voice+=c;
  }
  if(voice.length()>0)
  {
 //   Serial.print(voice);
  if(voice=="aarambha" || voice=="on" || voice=="shuru" || voice=="suru")
   {
    Serial.print(voice);
    Serial.print('\n');
    digitalWrite(7,HIGH);
   }
   if(voice == "Roha" || voice=="band" || voice=="ban" || voice=="of")
   {
    Serial.print(voice);
    Serial.print('\n');
    digitalWrite(7,LOW);
   }
   if(voice == "blink")
   {
    Serial.print(voice);
    Serial.print('\n');
    voice="";
    while(1)
    {
      if(Serial.available())
      {
        delay(20);
        char ch=Serial.read();
        if(ch=='#')
        {break;}
        voice+=ch;
      }
      if(voice=="stop")
      {
        digitalWrite(7,HIGH);
        break;
        voice="";
      }
      else
      {
      digitalWrite(7,HIGH);
      delay(500);
      digitalWrite(7,LOW);
      delay(500);
    }
    }
   }
  }
  voice="";
}
