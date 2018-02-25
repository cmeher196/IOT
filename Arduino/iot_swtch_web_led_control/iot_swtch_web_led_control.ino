#include <ESP8266WiFi.h>
WiFiServer server(80);
int a=1;
void setup() {
  // put your setup code here, to run once:
  pinMode(D4,OUTPUT);
  pinMode(D6,INPUT);
  digitalWrite(D4,HIGH);
Serial.begin(115200);
WiFi.begin("AndroidAP","helloOn8");
while(WiFi.status()!=WL_CONNECTED)
{
  delay(500);
  Serial.print(".");
}
server.begin();
Serial.print(WiFi.localIP());

}

void loop() {
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
  digitalWrite(D4,LOW);
 a=2;
}
  }
  if(a==2)
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
  client.println("<a href=\"OFF\">");
  client.println("OFF");
  client.println("</a>");
  client.println("</body>");
  client.println("</html>");
  delay(1);
  }
    }
}
    
 
