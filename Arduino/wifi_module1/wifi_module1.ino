#include<ESP8266WiFi.h>
WiFiServer server(80);
void setup() {
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
  if(!client)
  {
    return;
  }
  while(!client.available())
  {
    delay(1);
  }
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type:Text/HTML");
  client.println("");
  client.println("<HTML>");
  client.println("<body><h1>WelCome to My Server</h1><span><a href=\"https://www.gmail.com\">Open Gmail</a></body>");
  client.println("</HTML>");
}
