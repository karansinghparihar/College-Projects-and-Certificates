#include<SoftwareSerial.h>
SoftwareSerial wifi(2,3);

void setup()
{
Serial.begin(115200);
wifi.begin(115200);
digitalWrite(8,HIGH);
  
  }
  void loop()
  {
    if(Serial.available()>0)
    {
      String i="";
      i = Serial.readString();
      delay(1000);
      Serial.println(i);
     
        wifi.print(i);
        delay(1000);
       Serial.println("Serial block");
      }
    
    if(wifi.available()>0)
    {
      String j="";
      j = Serial.readString();
      delay(1000);
      Serial.println(j);
     
   
        delay(1000);
       Serial.println("wifi block");
      }
    

    
    }
