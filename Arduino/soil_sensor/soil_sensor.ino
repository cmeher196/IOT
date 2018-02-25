int soil_sensor_pin=A0;

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;
int output_value;
void setup()
{
  myservo.attach(9);
  pinMode(2,OUTPUT);
  digitalWrite(2,LOW);
  Serial.begin(9600);
  Serial.println("Reading from Sensor...");
  delay(1000); 
}
void loop() 
{
  output_value=analogRead(soil_sensor_pin);
  output_value=map(output_value,550,0,0,100);
  Serial.print("Moisture:");
  Serial.print(output_value);
  Serial.println("%");
  delay(1000);
  if(output_value>=30 && output_value<=70)
  {
    digitalWrite(2,HIGH);
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);// tell servo to go to position in variable 'pos'
    if(output_value>=30 && output_value<=70)
    {
      delay(15);
    }
    }
  }
  else
  {
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);
    digitalWrite(2,LOW);
  }
  }
}
