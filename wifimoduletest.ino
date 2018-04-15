#include <SoftwareSerial.h>
 
SoftwareSerial esp8266(2,3); // make RX Arduino line is pin 2, make TX Arduino line is pin 3.
                             // This means that you need to connect the TX line from the esp to the Arduino's pin 2
                             // and the RX line from the esp to the Arduino's pin 3
void setup()
{
  //digitalWrite(13,HIGH);
  Serial.begin(9600);
  esp8266.begin(9600); // your esp's baud rate might be different
}
 
void loop()
{
  if(esp8266.available()>0) // check if the esp is sending a message 
  {
    while(esp8266.available()>0)
    {
      // The esp has data so display its output to the serial window 
      char c = esp8266.read(); // read the next character.
      esp8266.flush();
      Serial.print(c);
    }  
  }
  //AT+CWJAP="Karan","karan@123@123@123"\r\n
  //AT+CIPSTART="TCP","karansinghparihar.ga",80\r\n
  //AT+CIPSEND=77\r\n
  //GET /reciever.php?room1=12&room2=34 HTTP/1.1\r\nHost: karansinghparihar.ga\r\n\r\n
  
 
 
  if(Serial.available()>0)
  {
    // the following delay is required because otherwise the arduino will read the first letter of the command but not the rest
    // In other words without the delay if you use AT+RST, for example, the Arduino will read the letter A send it, then read the rest and send it
    // but we want to send everything at the same time.
    delay(1000); 
    
    String command="";
    
    while(Serial.available()>0) // read the command character by character
    {
        // read one character
      command+=(char)Serial.read();
    }
    
    esp8266.println(command);// send the read character to the esp8266

  }
}
 
 
