#include<ESP8266WiFi.h>
WiFiServer server(80);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin("AndroidAP","helloOn8");//ssid-AndroidAP and password-helloOn8 fro wifi hotspot...
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
  client.println("<body>");
   client.println("<h1><center>WelCome to My Server</center></h1>");
    client.println("<div style=\"background-color: blue;color:black;padding: 50px\">");
      client.println("<div style=\"background-color:red;color:yellow;padding: 50px \">");
      client.println("<div style=\"background-color: yellow;padding:25px\">");
      client.println("<center><a href=\"http://www.advaita.io\">AVDAITA-IIIT BBSR TECNO CULT FEST</a></center> ");
      client.println("</div></div>");
  
      client.println("<div style=\"background-color:green;padding: 50px \">");
      client.println("<div style=\"background-color: white;color:black;padding:25px\">");
      client.println("<center><a href=\"https://www.google.co.in\">Hello World</a></center> ");
      client.println("</div></div>");
    client.println("</div>");
  client.println("</body>");
  client.println("</HTML>");
}
