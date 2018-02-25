#include<ESP8266WiFi.h>
WiFiServer server(80);
String request ;
int c=0; 
int x;
void setup() {
  // put your setup code here, to run once:
  pinMode(D4, OUTPUT);
  pinMode(D6,INPUT);
  digitalWrite(D4, HIGH);
  Serial.begin(115200);
  WiFi.begin("AndroidAP","helloOn8");
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  server.begin();
  Serial.print(WiFi.localIP());
}
void loop() 
{
  x=digitalRead(D6);
  if(x==HIGH)
  {
    while(x==HIGH)
    {
      x=digitalRead(D6);
    }
    c++;
  }
  if(c%2!=0)
  {
    digitalWrite(D4,LOW);
  }
  if(c%2==0)
  {
    digitalWrite(D4,HIGH);
  }
  
  WiFiClient client = server.available();
  if(client)
  {
    request = client.readStringUntil('\r');
     client.flush();
     if(request.indexOf("ON")!=-1)
     {
      digitalWrite(D4,LOW);
     }
     if(request.indexOf("OFF")!=-1)
    {
     digitalWrite(D4,HIGH);
    }
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type:Text/HTML");
    client.println("");
    client.println("<HTML>");
    client.println("<body>");
    client.println("<h1>INTERNET OF THINGS</h1><span><a href=\"ON\"><span>ON</SPAN></a><br><br><span><a href=\"OFF\"><span>OFF</SPAN></a><br><br></body>");
    client.println("</HTML>");
    while(!client.available())
  {
     delay(1);
  }
 
  }
  
   
}
