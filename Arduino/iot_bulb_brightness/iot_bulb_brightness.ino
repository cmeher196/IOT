#include<ESP8266WiFi.h>
WiFiServer server(80);
int counter=0;
void setup() {
  pinMode(D4,OUTPUT);
  analogWrite(D4,1023); //initially bulb off...
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
    analogWrite(D4,0);
  }
  if(request.indexOf("LOW")!=-1)
  {
     analogWrite(D4,1000);
  }
  if(request.indexOf("MEDIUM")!=-1)
  {
     analogWrite(D4,500); 
  }
  if(request.indexOf("HIGH")!=-1)
  {
     analogWrite(D4,100);
  }
  //html code start....
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type:Text/HTML");
  client.println("");
  client.println("<HTML>");
  client.println("<body>");
  client.println("<h1>INTERNET OF THINGS</h1>");
  client.println("<a href=\"ON\">ON</a><br><br>");
  client.println("<a href=\"LOW\">LOW</a><br><br>");
  client.println("<a href=\"MEDIUM\">MEDIUM</a><br><br>");
  client.println("<a href=\"HIGH\">HIGH</a><br><br>");
  client.println("</body>");
  client.println("</HTML>");
  
}

