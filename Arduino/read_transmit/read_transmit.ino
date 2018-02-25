char c,a[10];
int i=0;
void setup() {
  // put your setup code here, to run once:
//  pinMode(D4,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   while(!Serial.available());   /*available() return type is character*/
  c=Serial.read();
  delay(5);
  a[i]=c;
  i++;
   
  if(c=='\n')
  {
    for(int j=0;j<i;j++)
    {
      Serial.print(a[j]);
      delay(10);
    }
    i=0;
  }
}
