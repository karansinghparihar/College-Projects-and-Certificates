#include<SoftwareSerial.h>
SoftwareSerial myserial(2,3);
String i="";
String j="";

void setup() {
 Serial.begin(9600);
 myserial.begin(9600);
 /*Serial.println("starts here");
  
 myserial.println("AT+RST\r\n");
  myserial.println("AT\r\n");
   myserial.println("AT+CWMODE=1\r\n");
 myserial.println("AT+CWJAP=\"Karan\",\"karan@123@123@123\"\r\n");
 myserial.println("AT+CIPSTART=\"TCP\",\"192.168.1.1\",80\r\n");
 myserial.println("AT+CIPSEND=81\r\n");
 myserial.println("GET /receiver.php?room1=56&room2=23 HTTP/1.1\r\nHost: 192.168.1.1\r\n\r\n");

  Serial.println("END here");
*/
}



/*AT commands used in the video:

1.) Reset Module
AT+RST\r\n

2.) Join Access Point (Internet Router)
AT+CWJAP="ATT409","5654665991"\r\n

3.) Connec to website
AT+CIPSTART="TCP","esp8266.allaboutee.com",80\r\n

4.) Specify number of bytes you'll send

AT+CIPSEND=81\r\n

AT+CIPSEND=154\r\n


5.) Send GET Request

GET /receiver.php?apples=56&oranges=23 HTTP/1.1\r\nHost: esp8266.allaboutee.com\r\n\r\n

5.) send POST Request
POST /receiver.php HTTP/1.1\r\nHost: esp8266.allaboutee.com\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: 20\r\n\r\napples=12&oranges=45\r\n\r\n

PHP Script:*/
  

  
  void loop() {
  
if(Serial.available()>0)
{
  i=Serial.readString();
 

 
  myserial.println(i);

}

  if(myserial.available()>0)
{
  j=myserial.readString();
  Serial.println(j);
    
 



}




}
