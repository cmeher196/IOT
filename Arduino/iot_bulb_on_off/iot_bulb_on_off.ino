#include<ESP8266WiFi.h>
WiFiServer server(80);
int counter=0;
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
    client.println("<h1>INTERNET OF THINGS</h1><span><a href=\"ON\"><img src=\"https://cdn.pixabay.com/photo/2013/07/12/14/34/light-148483_960_720.png\"></a></body>");
    
  }
  if(counter==1)
  {
    client.println("<body>");
    client.println("<h1>INTERNET OF THINGS</h1><span><a href=\"OFF\"><img src=\"https://images.homedepot-static.com/productImages/bcdb5854-df4b-4b7e-bead-9d549995fcef/svn/smart-electric-led-bulbs-810-64_1000.jpg\"></a></body>");
    }
  client.println("</HTML>");
  
}
