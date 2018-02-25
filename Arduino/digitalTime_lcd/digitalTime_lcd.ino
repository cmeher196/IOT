#include<LiquidCrystal.h>
LiquidCrystal lcd(D0,D1,D2,D3,D4,D5);
int h1=0,h2=0,m1=0,m2=0,s1=0,s2=0;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
     lcd.setCursor(0,0);
     lcd.print("hr:mm:ss");
     delay(2000);
     lcd.setCursor(2,0);
     lcd.print(':');
     lcd.setCursor(5,0);
     lcd.print(':');
     for(int i=0;i<25;i++)
     {
      lcd.setCursor(0,0);
      lcd.print(h1,DEC);
      lcd.setCursor(1,0);
      lcd.print(h2,DEC);
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
        lcd.setCursor(4,0);
        lcd.print(m2,DEC);
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
          lcd.setCursor(7,0);
          lcd.print(s2,DEC);
          delay(500);
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
