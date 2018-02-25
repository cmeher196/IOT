#include<ESP8266WiFi.h>
WiFiServer server(80);
int counter=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.mode(WIFI_AP);
  WiFi.softAP("Chandra_hotspot","helloOn8");
  server.begin();
  Serial.print(WiFi.softAPIP());
  pinMode(D4,OUTPUT);
  digitalWrite(D4,HIGH);
}

void loop() {
  WiFiClient client=server.available();
  //Check for client...
  if(!client)
  {
    return;
  }
  //wait for request....
  while(!client.available())
  {
    delay(1);
  }
  //read request and perform task....
  String request=client.readStringUntil('\r');
  client.flush();
  if(request.indexOf("ON")!=-1)
  {
    digitalWrite(D4,LOW);
    counter=1;
  }
  if(request.indexOf("OFF")!=-1)
  {
    digitalWrite(D4,HIGH);
    counter=0;
  }
   
  
  //html page start....
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type:Text/HTML");
  client.println("");
  client.println("<HTML>");
  if(counter==0)
  {
    client.println("<body>");
    client.println("<h1>INTERNET OF THINGS</h1><span><a href=\"ON\">ON</a></body>");
    
  }
  if(counter==1)
  {
    client.println("<body>");
    client.println("<h1>INTERNET OF THINGS</h1><span><a href=\"OFF\">OFF</a></body>");
    }
  client.println("</HTML>");
  

}
