#include<ESP8266WiFi.h>
WiFiServer server(80);
int a=1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.mode(WIFI_AP);
  WiFi.softAP("Chandra_hotspot","helloOn8");
  server.begin();
  Serial.print(WiFi.softAPIP());
  pinMode(D4,OUTPUT);
  analogWrite(D4,1023);
}

void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient client=server.available();
  if(!client)
  {
    if(a==1)
    {
      if(digitalRead(D6)==HIGH)
      {
        a=2;
        delay(50);
        digitalWrite(D4,LOW);
        while(digitalRead(D6)==HIGH)
        {
          
        }
      }
    }
    if(a==2)
    {
      if(digitalRead(D6)==HIGH)
      {
        a=1;
        delay(50);
        digitalWrite(D4,HIGH);
        while(digitalRead(D6)==HIGH)
        {

        }
        }
      }
    }
if(client)
    {
   while(!client.available())
  {
    delay(1);
  }
  String request;
  request=client.readStringUntil('\r');
  client.flush();
  if(a==1)
  {
    if(request.indexOf("ON")!=-1)
  {
    analogWrite(D4,0);
    a=2;
  }
  if(a==2)
  {
    if(request.indexOf("LOW")!=-1)
  {
    analogWrite(D4,1000);
    a=3;
  }
 
  }
  if(a==3)
  {
    if(request.indexOf("MED")!=-1)
    {
      analogWrite(D4,512);
      a=4;
    }
  }
  if(a==4)
  {
    if(request.indexOf("HIGH")!=-1)
    {
      analogWrite(D4,10);
      a=1;
    }
  }
  if(a==5)
  {
    if(request.indexOf("OFF")!=-1)
    {
      digitalWrite(D4,HIGH);
      a=1;
    }
  }
  if(a==1)
  {
  client.println("HTTP/1.1 200 OK");
  client.println("Content_Type:Text/HTML");
  client.println("");
  client.println("<HTML>");
  client.println("<HEAD>");
  client.println("</HEAD>");
  client.println("<BODY>");
  client.println("<h1>LED is OFF</h1>");
  client.println("<a href=\"ON\">");
  client.println("ON");
  client.println("</a>");
  client.println("<br>");
  client.println("<a href=\"LOW\">");
  client.println("LOW");
  client.println("</a>");
  client.println("<br>");
  client.println("<a href=\"MED\">");
  client.println("MED");
  client.println("</a>");
  client.println("<br>");
  client.println("<a href=\"HIGH\">");
  client.println("HIGH");
  client.println("</a>");
  client.println("<br>");
  client.println("<a href=\"OFF\">");
  client.println("OFF");
  client.println("</a>");
  client.println("</body>");
  client.println("</html>");
  delay(1);
  }
  if(a==2)
  {
     client.println("HTTP/1.1 200 OK");
  client.println("Content_Type:Text/HTML");
  client.println("");
  client.println("<HTML>");
  client.println("<HEAD>");
  client.println("</HEAD>");
  client.println("<BODY>");
  client.println("<h1>LED is OFF</h1>");
  client.println("<a href=\"ON\">");
  client.println("ON");
  client.println("</a>");
  client.println("<br>");
  client.println("<a href=\"LOW\">");
  client.println("LOW");
  client.println("</a>");
  client.println("<br>");
  client.println("<a href=\"MED\">");
  client.println("MED");
  client.println("</a>");
  client.println("<br>");
  client.println("<a href=\"HIGH\">");
  client.println("HIGH");
  client.println("</a>");
  client.println("<br>");
  client.println("<a href=\"OFF\">");
  client.println("OFF");
  client.println("</a><br>");
  client.println("</body>");
  client.println("</html>");
  delay(1);
  }
 if(a==3)
  {
     client.println("HTTP/1.1 200 OK");
  client.println("Content_Type:Text/HTML");
  client.println("");
  client.println("<HTML>");
  client.println("<HEAD>");
  client.println("</HEAD>");
  client.println("<BODY>");
  client.println("<h1>LED is OFF</h1>");
  client.println("<a href=\"ON\">");
  client.println("ON");
  client.println("</a>");
  client.println("<br>");
  client.println("<a href=\"LOW\">");
  client.println("LOW");
  client.println("</a>");
  client.println("<br>");
  client.println("<a href=\"MED\">");
  client.println("MED");
  client.println("</a>");
  client.println("<br>");
  client.println("<a href=\"HIGH\">");
  client.println("HIGH");
  client.println("</a>");
  client.println("<br>");
  client.println("<a href=\"OFF\">");
  client.println("OFF");
  client.println("</a><br>");
  client.println("</body>");
  client.println("</html>");
  delay(1);
  }

  if(a==4)
  {
     client.println("HTTP/1.1 200 OK");
  client.println("Content_Type:Text/HTML");
  client.println("");
  client.println("<HTML>");
  client.println("<HEAD>");
  client.println("</HEAD>");
  client.println("<BODY>");
  client.println("<h1>LED is OFF</h1>");
  client.println("<a href=\"ON\">");
  client.println("ON");
  client.println("</a>");
  client.println("<br>");
  client.println("<a href=\"LOW\">");
  client.println("LOW");
  client.println("</a>");
  client.println("<br>");
  client.println("<a href=\"MED\">");
  client.println("MED");
  client.println("</a>");
  client.println("<br>");
  client.println("<a href=\"HIGH\">");
  client.println("HIGH");
  client.println("</a>");
  client.println("<br>");
  client.println("<a href=\"OFF\">");
  client.println("OFF");
  client.println("</a><br>");
  client.println("</body>");
  client.println("</html>");
  delay(1);
  }
  if(a==1)
  {
  client.println("HTTP/1.1 200 OK");
  client.println("Content_Type:Text/HTML");
  client.println("");
  client.println("<HTML>");
  client.println("<HEAD>");
  client.println("</HEAD>");
  client.println("<BODY>");
  client.println("<h1>LED is OFF</h1>");
  client.println("<a href=\"ON\">");
  client.println("ON");
  client.println("</a>");
  client.println("<br>");
  client.println("<a href=\"LOW\">");
  client.println("LOW");
  client.println("</a>");
  client.println("<br>");
  client.println("<a href=\"MED\">");
  client.println("MED");
  client.println("</a>");
  client.println("<br>");
  client.println("<a href=\"HIGH\">");
  client.println("HIGH");
  client.println("</a>");
  client.println("<br>");
  client.println("<a href=\"OFF\">");
  client.println("OFF");
  client.println("</a>");
  client.println("</body>");
  client.println("</html>");
  delay(1);
  }
    }
}
}
