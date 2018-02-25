#include<string.h>
#include<ESP8266WiFi.h>
WiFiServer server(80);
String request ;
int flag = 1023; 
void setup() {
  // put your setup code here, to run once:
  pinMode(D4, OUTPUT);
  digitalWrite(D4, HIGH);
  Serial.begin(115200);
  WiFi.begin("AndroidAp", "helloOn8");
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  server.begin();
  Serial.print(WiFi.localIP());
  
}

void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient client = server.available();
  if(!client)
  {
    return ;
  }
  while(!client.available())
  {
    delay(1);
  }
  request = client.readStringUntil('\r');
  client.flush();
  if(request.indexOf("HIGH?Submit=HIGH") != -1)
  {
    if(flag >= 200)
    {
      flag = flag - 200;
    }
    analogWrite(D4, flag);
  }
  else if(request.indexOf("LOW?Submit=LOW") != -1)
  {
    if(flag < 800)
    {
      flag = flag + 200;
    }
    else
    {
      flag = 1023;
    }
    analogWrite(D4, flag);
  }
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type : Text/HTML");
  client.println("");
  client.println("<html>");
  client.println("<head>");
  client.println("<title>IOT</title>");
  client.println("</head>");
  client.println("<body><center><h1>Internet Of Things</h1>");
    client.println("<form action=\"HIGH\"><input type=\"submit\" value=\"HIGH\" name=\"Submit\"/></form>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<form action=\"LOW\"><input type=\"submit\" value=\"LOW\" name=\"Submit\"/></form>");
  client.println("</center></body>");
  client.println("</html>");
delay(1);
}
