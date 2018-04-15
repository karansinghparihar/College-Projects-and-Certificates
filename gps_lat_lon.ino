#include<SoftwareSerial.h>
#include<TinyGPS.h>
TinyGPS gps;
long lat,lon;
SoftwareSerial gpsSerial(2,3);
void setup()
{
  Serial.begin(9600);
 
  
  gpsSerial.begin(9600);
}
void loop()
{

  while(gpsSerial.available())
  {
    if(gps.encode(gpsSerial.read()))
    {
      gps.get_position(&lat,&lon);
      Serial.print("latitude is =");
      Serial.println(lat);
      Serial.print("longitude =");
      Serial.println(lon);
      
    }
  }
}

