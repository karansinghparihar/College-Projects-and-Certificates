#include<SoftwareSerial.h>
SoftwareSerial mySerial(9,10);
void send_from_mobile_to_arduino();
void send_from_arduino_to_mobile(); 
int t;
char c;
void setup() {
 mySerial.begin(9600);
 Serial.begin(9600);
 pinMode(13,OUTPUT);
}

void loop() {
  //Serial.println("this is serial communication between serial monitor and arduino through pin 0,1");
  delay(1000);
  if(Serial.available()>0)
  {
    c=Serial.read();
    Serial.print("entered choice is = ");
    Serial.println(c);
    delay(1000);
    switch(c)
    {
      case 115:
      Serial.println("mobile sends data to arduino via bluetooth module");
      delay(1000);
      send_from_mobile_to_arduino();
      delay(1000);
      Serial.println("now data from mobile to arduino is stops");
      delay(1000);
      break;
      case 114:
      Serial.println("arduino sends data to mobile via bluetooth module");
      delay(1000);
      send_from_arduino_to_mobile();     
      delay(1000);
      Serial.println("now data from arduino to mobile stps");
      delay(1000);
      break;
    }
  }
  if(mySerial.available()>0)
  {
    Serial.println("data is recieved by arduino from bluetooth via pin 9,10");
    t=mySerial.read();
    delay(1000);
    Serial.print("value of t = ");
    Serial.println(t);
    delay(1000);
    Serial.println("now we use switch case to start and off motor");
  }

}
void send_from_mobile_to_arduino()
{
  Serial.println("send_from_mobile_to_arduino");
}
void send_from_arduino_to_mobile()
{
  Serial.println("send_from_arduino_to_mobile");
}

