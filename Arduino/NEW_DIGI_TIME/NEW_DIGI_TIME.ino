#include<LiquidCrystal.h>
LiquidCrystal lcd(D0,D1,D2,D3,D4,D5); //these pins r the value of mcu not of lcd
int c=0,x;
int shr1=0,shr2=0,sm1=0,sm2=0,ss1=0,ss2=0;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  pinMode(D6,INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  x=digitalRead(D6);
  if(x==HIGH)
  {
    while(x==HIGH)
    {
      X=digitalRead(D6);
    }
    c++;
  }
  if(c%2!=0)
  {
    lcd.setCursor(2,0);
     lcd.print(':');
     lcd.setCursor(5,0);
     lcd.print(':');
     for(int i=0;i<25;i++)
     {
      lcd.setCursor(0,0);
      lcd.print(h1,DEC);
      sh1=h1;
      lcd.setCursor(1,0);
      lcd.print(h2,DEC);
      sh2=h2;
      h2++;
      if(h2==10)
      {
        h1++;
        h2=0;
      }
      else if(h1==2 && h2==5)
      {
        h1=0;
        h2=0;
        m1=0;
        m2=0;
        s1=0;
        s2=0;
      }
      
      for(int j=0;j<60;j++)
      {
        lcd.setCursor(3,0);
        lcd.print(m1,DEC);
        sm1=m1;
        lcd.setCursor(4,0);
        lcd.print(m2,DEC);
        sm2=m2;
        m2++;
        if(m2==10)
        {
          m1++;
          m2=0;
        }
        
        for(int m=0;m<60;m++)
        {
          lcd.setCursor(6,0);
          lcd.print(s1,DEC);
          ss1=s1;
          ss2=s2;
          lcd.setCursor(7,0);
          lcd.print(s2,DEC);
          delay(100); 
          s2++;
          if(s2==10)
          {
            s1++;
            s2=0;
          }
        }
        s1=0;s2=0;
      }
      m1=0; m2=0;
     }
  }
  else if(c%2==0)
  {
    lcd.clear();
    lcd.print("sh1"+"sh2"+":"+"sm1"+"sm2"+"ss1"+"ss2");
  }
}
