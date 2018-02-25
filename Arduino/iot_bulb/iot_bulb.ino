#include<ESP8266WiFi.h>
WiFiServer server(80);
void setup() {
  pinMode(D4,OUTPUT);
  digitalWrite(D4,HIGH); //initially bulb off...
  // put your setup code here, to run once:
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
  }
  //html page start....
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type:Text/HTML");
  client.println("");
  client.println("<HTML>");
  client.println("<body><h1>INTERNET OF THINGS</h1><span><a href=\"ON\">ON BULB</a></body>");
  client.println("</HTML>");
  
}
