#include <Wire.h>
String apiKey = "XUEYYQLDJU4HRW05";
#include<SoftwareSerial.h>
SoftwareSerial ser(2,3);
int LED = 13;

//int x = 1,
int a = 1;
//int x = 2;
int b = 1;
int x = 3;
int c = 1;
void setup() {
  // Define the LED pin as Output
  pinMode (LED, OUTPUT);
   ser.begin(9600);
   Serial.begin(9600);
  
  // reset ESP8266
  ser.println("AT+RST");
  // Start the I2C Bus as Slave on address 9
  Wire.begin(8); 
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
}
void receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the I2C
}
void loop() {
  //If value received is 0 blink LED for 200 ms
/*  if (x == '0') {
    digitalWrite(LED, HIGH);
    delay(200);
    digitalWrite(LED, LOW);
    delay(200);
  }*/
  //If value received is 3 blink LED for 400 ms
  if (x == 1 &&  (a==1 || a==2 || a==3 || a==4 || a==5)) {
    digitalWrite(LED, HIGH);
    esp_8266a();
    a++;
   // delay(400);
    ///digitalWrite(LED, LOW);
   /// delay(400);
  }
   if (x == 2 &&  (b==1 || b==2 || b==3 || b==4 || b==5)) {
    digitalWrite(LED, LOW);
    esp_8266d();
    b++;
   // delay(400);
    ///digitalWrite(LED, LOW);
   /// delay(400);
  }
  if (x == 3 && (c==1 || c==2 || c==3 || c==4 || c==5)) {
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
    esp_8266t();
    c++;
   // delay(400);
    ///digitalWrite(LED, LOW);
   /// delay(400);
  }
}
void esp_8266a()
{
  Serial.println("activate starts");
 // convert to string
  char buf[32];
  //String strVolt = dtostrf( bat_volt, 4, 1, buf);
  String strVolt;
  strVolt = 50;
  Serial.print(strVolt);
  Serial.println(" V");
  // TCP connection
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += "184.106.153.149"; // api.thingspeak.com
  cmd += "\",80";
  ser.println(cmd);
   
  if(ser.find("Error")){
    Serial.println("AT+CIPSTART error");
    return;
  }
  
  // prepare GET string
  String getStr = "GET /update?api_key=";
  getStr += apiKey;
  getStr +="&field1=";
  getStr += String(strVolt);
  getStr += "\r\n\r\n";

  // send data length
  cmd = "AT+CIPSEND=";
  cmd += String(getStr.length());
  ser.println(cmd);

  if(ser.find(">")){
    ser.print(getStr);
  }
  else{
    ser.println("AT+CIPCLOSE");
    // alert user
    Serial.println("AT+CIPCLOSE");
  }
    
  // thingspeak needs 15 sec delay between updates
  delay(1000);  
  Serial.println("activate ends");
}

void esp_8266d()
{
  Serial.println("deactivate start");
 // convert to string
  char buf[32];
  //String strVolt = dtostrf( bat_volt, 4, 1, buf);
  String strVolt;
  strVolt = 40;
  Serial.print(strVolt);
  Serial.println(" V");
  // TCP connection
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += "184.106.153.149"; // api.thingspeak.com
  cmd += "\",80";
  ser.println(cmd);
   
  if(ser.find("Error")){
    Serial.println("AT+CIPSTART error");
    return;
  }
  
  // prepare GET string
  String getStr = "GET /update?api_key=";
  getStr += apiKey;
  getStr +="&field2=";
  getStr += String(strVolt);
  getStr += "\r\n\r\n";

  // send data length
  cmd = "AT+CIPSEND=";
  cmd += String(getStr.length());
  ser.println(cmd);

  if(ser.find(">")){
    ser.print(getStr);
  }
  else{
    ser.println("AT+CIPCLOSE");
    // alert user
    Serial.println("AT+CIPCLOSE");
  }
    
  // thingspeak needs 15 sec delay between updates
  delay(1000);  
  Serial.println("deactivate ends");
}

/*void esp_8266d()
{
  Serial.println("deactivate starts");
 // convert to string
  char buf[32];
  //String strVolt = dtostrf( bat_volt, 4, 1, buf);
  String strVolt;
  strVolt = 40;
  Serial.print(strVolt);
  Serial.println(" V");
  // TCP connection
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += "184.106.153.149"; // api.thingspeak.com
  cmd += "\",80";
  ser.println(cmd);
   
  if(ser.find("Error")){
    Serial.println("AT+CIPSTART error");
    return;
  }
  
  // prepare GET string
  String getStr = "GET /update?api_key=";
  getStr += apiKey;
  getStr +="&field2=";
  getStr += String(strVolt);
  getStr += "\r\n\r\n";

  // send data length
  cmd = "AT+CIPSEND=";
  cmd += String(getStr.length());
  ser.println(cmd);

  if(ser.find(">")){
    ser.print(getStr);
  }
  else{
    ser.println("AT+CIPCLOSE");
    // alert user
    Serial.println("AT+CIPCLOSE");
  }
    
  // thingspeak needs 15 sec delay between updates
  delay(1000);  
  Serial.println("deactivate ends");
}
*/

void esp_8266t()
{
  Serial.println("thief starts");
 // convert to string
  char buf[32];
  //String strVolt = dtostrf( bat_volt, 4, 1, buf);
  String strVolt;
  strVolt = 40;
  Serial.print(strVolt);
  Serial.println(" V");
  // TCP connection
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += "184.106.153.149"; // api.thingspeak.com
  cmd += "\",80";
  ser.println(cmd);
   
  if(ser.find("Error")){
    Serial.println("AT+CIPSTART error");
    return;
  }
  
  // prepare GET string
  String getStr = "GET /update?api_key=";
  getStr += apiKey;
  getStr +="&field3=";
  getStr += String(strVolt);
  getStr += "\r\n\r\n";

  // send data length
  cmd = "AT+CIPSEND=";
  cmd += String(getStr.length());
  ser.println(cmd);

  if(ser.find(">")){
    ser.print(getStr);
  }
  else{
    ser.println("AT+CIPCLOSE");
    // alert user
    Serial.println("AT+CIPCLOSE");
  }
    
  // thingspeak needs 15 sec delay between updates
  delay(1000); 
  Serial.println("thief ends"); 
}
