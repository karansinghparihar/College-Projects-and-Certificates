#include <LiquidCrystal.h> // includes the LiquidCrystal Library 
#include <Keypad.h>
#include <SoftwareSerial.h>
void esp_8266a();
void esp_8266d();
void esp_8266t();
String apiKey = "XUEYYQLDJU4HRW05";
//#define buzzer 8
//SoftwareSerial mySerial(4,5);
SoftwareSerial ser(2,3);
//int Contrast=20;

int led=13;
int IR;
int ir =12;
//float sample=0;
int screenOffMsg =0;
String password="1234";
String tempPassword;
boolean activated = false; // State of the alarm
boolean isActivated;
boolean activateAlarm = true;
boolean alarmActivated = false;
boolean enteredPassword; // State of the entered password to stop the alarm
boolean passChangeMode = false;
boolean passChanged = false;
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keypressed;
//define the cymbols on the buttons of the keypads
char keyMap[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
//byte rowPins[ROWS] = {4,5,6,7}; //Row pinouts of the keypad
//byte colPins[COLS] = {8,9,10,11}; //Column pinouts of the keypad
byte rowPins[ROWS] = {6,7,A0,A1}; //Row pinouts of the keypad
byte colPins[COLS] = {A2,A3,A4,A5}; //Column pinouts of the keypad
Keypad myKeypad = Keypad( makeKeymap(keyMap), rowPins, colPins, ROWS, COLS); 
//LiquidCrystal lcd(A0,A1,A2,A3,A4,A5); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7) 
// LiquidCrystal lcd(10, 11, 5, 4, 3, 2);
void setup() { 
  pinMode(9,OUTPUT);
    //analogWrite(6,Contrast);
   //  lcd.begin(16, 2);
     //analogWrite(9,200);
 // lcd.begin(16,2); 
  
  Serial.begin(9600);
   ser.begin(9600);
   ser.println("AT+RST");
  //mySerial.begin(9600);
 // pinMode(buzzer, OUTPUT);
  pinMode(ir, INPUT);
  //pinMode(led, OUTPUT);
   //esp_8266d();
  Serial.print("ACTUAL PASSWORD  : ");
  Serial.println(password);

  
    

    
 // mySerial.write("ATD9602964561;\r");//Phone number you want to call
       //   delay(16000);
         // mySerial.print("ATH;\r");
}

void loop() {
  
  if (activateAlarm) {
    Serial.print("ALARM IS ACTIVATED NOW: ");
   // lcd.clear();
    //lcd.setCursor(0,0);
    //lcd.print("ALARMON");
    //delay(2000);
   // lcd.clear();
   // delay(2000);
  //  lcd.setCursor(0,1);
   // lcd.println("IR");
    // delay(2000);
     //lcd.clear();
     //delay(2000);
       /* lcd.setCursor(0,0);
        lcd.println("ENTERPASS");
        delay(2000);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("PASS CORRECT");
        delay(2000);
        lcd.setCursor(0,1);
        lcd.print("ALARM OFF");
        delay(2000);
        lcd.clear();
        //lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("PASSWORD WRONG");
        delay(2000);
        lcd.setCursor(0,1);
        lcd.print("GSM CALL");
        delay(2000);
        lcd.clear();
        //lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("A - Activate");
      delay(2000);
      lcd.setCursor(0,1);
      lcd.print("B - Change Pass");
      delay(2000);


      */
    //lcd.setCursor(0,1);
    //lcd.print("VATED NOW:");
   // lcd.clear();
    //lcd.setCursor(0,0);
    //lcd.print("Alarm Activated!");
    //initialDistance = getDistance();
   // lcd.setCursor(0,0);
   // lcd.print("ALARM IS ON NOW!");
  //  delay(2000);
  //  lcd.clear();
    activateAlarm = false;
    alarmActivated = true;
   // digitalWrite(led,HIGH);
    //delay(2000);
  }
 
    if (alarmActivated == true){
    // int IR = digitalRead(12);
    IR=1;
      if (IR==HIGH)
      {
        Serial.println("IR VALUE HIGH");
        lcd.setCursor(0,1);
        lcd.println("IR SENSOR HIGH  ");
        delay(2000);
        lcd.clear();
        tone(buzzer, 1000); // Send 1KHz sound signal 
        //lcd.clear();
        //lcd.setCursor(0,0);
        //lcd.println("IR HIGH");
        //lcd.setCursor(0,1);
        //lcd.println("91*********");
        //delay(1000);
        //lcd.clear();
/*    //SEND MESSAGE FROM GSM.
      Serial.println("MESSAGE START NOW");
      mySerial.println("AT+CMGF=1"); // set the SMS mode to text
      delay(500);
      mySerial.write("AT+CMGS=");
      mySerial.write(34); //ASCII of "
      mySerial.write("+917611942803");
      mySerial.write(34);
      mySerial.write(13);
      mySerial.write(10);
      delay(500);
      mySerial.println("HELLO THIS IS MESSAGE FROM GSM"); //this is the message to be sent
      delay(2500);
      mySerial.write(26);//Ascii code of ctrl+z to send the message
      mySerial.write(13);
      mySerial.write(10);
      delay(500);
      Serial.println("MESSAGE END");
*/

Serial.println("ENTER PASSWORD TO DEACTIVATE ALARM : ");
 //lcd.setCursor(0,0);
       // lcd.println("ENTER PASS");
       // lcd.setCursor(0,1);
      //  lcd.println("TO DEACTIVATE");
    lcd.setCursor(0,0);
    lcd.print("ENTER PASSWORD!");
    delay(2000);
    lcd.setCursor(0,1);
    lcd.print("TO DEACTIVATE : ");
    delay(2000);
    lcd.clear();
enterPassword();
lcd.clear();
Serial.print("ENTER 'A' TO ACTIVATE ALARM or ");
Serial.println("ENTER 'B' TO RESET PASSWORD ");
//Serial.println("CALL FROM GSM START");
  lcd.setCursor(0,0);
    lcd.print("rrrrrr ");
//mySerial.write("ATD +919602820047;\r");//Phone number you want to call
//delay(5000);
//mySerial.print("ATH;\r");
//Serial.println("CALL FROM GSM END");
}
 }
 
  if (!alarmActivated) {
    if (screenOffMsg == 0 ){
      //lcd.clear();
     // lcd.setCursor(0,0);
     // lcd.print("A - Activate");
     // lcd.setCursor(0,1);
    //  lcd.print("B - Change Pass");
    lcd.setCursor(0,0);
    lcd.print("A->ACTIVATE");
   // delay(2000);
    lcd.setCursor(0,1);
    lcd.print("B->RESET");
    //delay(2000);
    lcd.clear();
      screenOffMsg = 1;
    }
    keypressed = myKeypad.getKey();
     if (keypressed =='A'){        //If A is pressed, activate the alarm
      tone(buzzer, 1000, 200);
      activateAlarm = true; 
       lcd.setCursor(0,0);
    lcd.print("ACTIVATE");
    //delay(2000);
    lcd.setCursor(0,1);
    lcd.print("ALARM AGAIN");
   // delay(2000);
    lcd.clear();
      Serial.print("INSIDE 'A' KEYPRESSED : ");
      Serial.println(keypressed);
      //digitalWrite(led,HIGH);
      activateAlarm = true;
      for(int i=0;i<15;i++)
 { esp_8266a();}
    }
    else if (keypressed =='B') {
      //lcd.clear();
      Serial.print("INSIDE 'B' KEYPRESSED : ");
      Serial.println(keypressed);
      Serial.println("ENTER YOUR CURRENT PASSWORD : ");
      int i=1;
      lcd.setCursor(0,0);
    lcd.print("RESET");
   // delay(2000);
    lcd.setCursor(0,1);
    lcd.print("PASSWORD");
  //  delay(2000);
    lcd.clear();
      tone(buzzer, 2000, 100);
      tempPassword = "";
     // lcd.setCursor(0,0);
  
     // lcd.print("Current Password");
     // lcd.setCursor(0,1);
     // lcd.print(">");
    lcd.setCursor(0,0);
    lcd.print("ENTER CURRENT");
 //   delay(2000);
    lcd.setCursor(0,1);
    lcd.print("PASSWORD");
   // delay(2000);
    lcd.clear();
      passChangeMode = true;
      passChanged = true;    
      while(passChanged) {      
      keypressed = myKeypad.getKey();
      if (keypressed != NO_KEY){
        if (keypressed == '0' || keypressed == '1' || keypressed == '2' || keypressed == '3' ||
            keypressed == '4' || keypressed == '5' || keypressed == '6' || keypressed == '7' ||
            keypressed == '8' || keypressed == '9' ) {
         tempPassword += keypressed;
         lcd.setCursor(i,1);
         lcd.print(keypressed);
        // delay(2000);
         i++;
     
         Serial.println(keypressed);

         tone(buzzer, 2000, 100);
        }
       // Serial.print("YOU ENTERED : ");
        //Serial.println(tempPassword);
      }
     
      
      if (i > 5 || keypressed == '#') {
        tempPassword = "";
        i=1;
        Serial.println("WRITE YOUR PASSWORD AGAIN : ");
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Current Password");
        lcd.setCursor(0,1);
        lcd.print(">"); 
      }
      if ( keypressed == '*') {
        i=1;
        Serial.print("YOU ENTERED : ");
        Serial.println(tempPassword);
        //passChangeMode=true;
        tone(buzzer, 2000, 100);
        if (password == tempPassword) {
          tempPassword="";
         // digitalWrite(led,HIGH);
         
          Serial.println("YOUR ENTERED PASSWORD IS SAME AS ACTUAL PASSWORD  : ");
          Serial.println("ENTER YOUR NEW PASSWORD : ");
          lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("ENTER New Password");
          lcd.setCursor(0,1);
          lcd.print(">");
          while(passChangeMode) {///////////////////////////GALTI
            //Serial.println("TEST 1 ");
            keypressed = myKeypad.getKey();
            if (keypressed != NO_KEY){
              if (keypressed == '0' || keypressed == '1' || keypressed == '2' || keypressed == '3' ||
                  keypressed == '4' || keypressed == '5' || keypressed == '6' || keypressed == '7' ||
                  keypressed == '8' || keypressed == '9' ) {
                tempPassword += keypressed;
                lcd.setCursor(i,1);
                lcd.print(keypressed);
              //  delay(2000);
                i++;
                Serial.println(keypressed); 
                //Serial.println("TEST 1 ");
                tone(buzzer, 2000, 100);
              }
             
            }
            if (i > 5 || keypressed == '#') {
              tempPassword = "";
              i=1;
              Serial.println("WRITE YOUR PASSWORD AGAIN : ");
             
              tone(buzzer, 2000, 100);
              lcd.clear();
              lcd.setCursor(0,0);
              lcd.print("Set New Password");
              lcd.setCursor(0,1);
              lcd.print(">");
            }
            if ( keypressed == '*') {
              i=1;
              tone(buzzer, 2000, 100);
              password = tempPassword;
              passChangeMode = false;
              passChanged = false;
              screenOffMsg = 0;
              Serial.print(" YOUR NEW Password : ");
              Serial.println(password);
               activateAlarm = true;
                lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("YOUR NEW");
  //  delay(2000);
    lcd.setCursor(0,1);
    lcd.print("PASSWORD:");
  //  delay(2000);
    lcd.clear();
      lcd.setCursor(0,0);
    lcd.print(password);
    delay(2000);
 //   lcd.clear();

              //digitalWrite(led,LOW);
            }            
          }
        }
      }
    }
   }
 }
}
void enterPassword() {
 // mySerial.println("AT+CMGF=1"); // set the SMS mode to text
//delay(500);
//mySerial.write("AT+CMGS=");
//mySerial.write(34); //ASCII of "
//mySerial.write("+919783952043");
//mySerial.write(34);
//mySerial.write(13);
//mySerial.write(10);
//delay(1000);
//mySerial.println("hello"); //this is the message to be sent
//delay(2500);
//mySerial.write(26);
//mySerial.write(13);
//mySerial.write(10);//Ascii code of ctrl+z to send the message
//delay(500);
//while(1)

  int k=5;
  tempPassword = "";
  activated = true;
  //lcd.clear();
  //lcd.setCursor(0,0);
  //lcd.print(" * ALARM * ");
  //lcd.setCursor(0,1);
  //lcd.print("Pass>");
      while(activated) {
      keypressed = myKeypad.getKey();
      if (keypressed != NO_KEY){
        if (keypressed == '0' || keypressed == '1' || keypressed == '2' || keypressed == '3' ||
            keypressed == '4' || keypressed == '5' || keypressed == '6' || keypressed == '7' ||
            keypressed == '8' || keypressed == '9' ) {
          tempPassword += keypressed;
         // lcd.setCursor(k,1);
         // lcd.print(keypressed);
          lcd.setCursor(k,1);
    lcd.print(keypressed);
    //delay(2000);
    
          k++;
          Serial.println(keypressed);
          
        }
      }
      if (k > 9 || keypressed == '#') {
        tempPassword = "";
        k=5;
         Serial.println("INSIDE ENTERPASSWORD() MORE THAN 4 DIGITS  : ");
        lcd.clear();
        lcd.setCursor(0,0);
       lcd.print(" * ALARM * ");
        lcd.setCursor(0,1);
        lcd.print("Pass>");
      }
      if ( keypressed == '*') {
        if ( tempPassword == password ) {
          activated = false;
          activateAlarm = false;
          alarmActivated = false;
          noTone(buzzer);
          lcd.clear();
       // lcd.setCursor(0,0);
       // lcd.print("PASS CORRECT");
        //lcd.setCursor(0,1);
       // lcd.print("ALARM OFF");
        //lcd.clear();
        lcd.setCursor(0,0);
    lcd.print("PASSWORD CORRECT");
    //delay(2000);
    lcd.setCursor(0,1);
    lcd.print("ALARM DEACTIVATE");
    //delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("YOU MAY ");
  //  delay(2000);
    lcd.setCursor(0,1);
    lcd.print("ENTER NOW");
    delay(2000);
    lcd.clear();
      //lcd.setCursor(0,0);
    //lcd.print("eeeee ");
     //lcd.clear();
        //lcd.setCursor(0,0);
        //lcd.print(tempPassword);
          Serial.print("YOUR PASSWORD IS SUBMITTED AND ITS CORRECT : ");
          Serial.println(tempPassword);
          Serial.println("NOW ALARM DEACTIVATE");
          
         // digitalWrite(13,LOW);
          for(int i=0;i<15;i++)
 { esp_8266d();}
          screenOffMsg = 0; 
        }
        else if (tempPassword != password) {
         // lcd.setCursor(0,1);
         // lcd.print("LOL!");
        //  delay(1000);
        //  lcd.clear();
         // lcd.clear();
       // lcd.setCursor(0,0);
      //  lcd.print("PASSWORD WRONG");
      //  lcd.setCursor(0,1);
      //  lcd.print("GSM CALL");
      //  lcd.clear();
      lcd.setCursor(0,0);
    lcd.print("PASSWORD WRONG");
   // delay(2000);
     lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("GSM CALL AND");
    //delay(2000);
     lcd.setCursor(0,1);
    lcd.print("SMS TO OWNER");
    //delay(2000);
    lcd.clear();
          Serial.print("YOUR PASSWORD IS SUBMITTED AND ITS INCORRECT NOW I CALL HOUSE OWNER : ");
          Serial.println("CALL FROM GSM START");
         // mySerial.write("ATD9602964561;\r");//Phone number you want to call
          delay(16000);
        //  mySerial.print("ATH;\r");
          Serial.println("CALL FROM GSM END");
         for(int i=0;i<15;i++)
 { esp_8266t();}
          //activateAlarm = true;
          //lcd.setCursor(0,0);
          //lcd.print(" * ALARM * ");
         // lcd.setCursor(0,1);
          //lcd.print("Pass>");
        }
      }    
    }
}
void esp_8266a()/////////GALTIII
{
  Serial.println("ACTIVATE START");
 // convert to string
  char buf[32];
  String strVolt;
 // String strVolt = dtostrf( bat_volt, 4, 1, buf);
  strVolt=100;
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
  /*if(a=0)
  {
    getStr +="&field1=";
  }
  else if(d=0)
  {
    getStr +="&field2=";
  }
  else if(t=0)
  {
    getStr +="&field3=";
  }*/
  getStr += String(strVolt);
  getStr += "\r\n\r\n";
//GET /update?api_key=XUEYYQLDJU4HRW05&field1=76\r\n\r\n
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
  Serial.println("ACTIVATE END");
}

void esp_8266d()
{
  Serial.println("DEACTIVATE START");
 // convert to string
  char buf[32];
  String strVolt;
 // String strVolt = dtostrf( bat_volt, 4, 1, buf);
  strVolt=79;
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
  Serial.println("DEACTIVATE END");
}
void esp_8266t()
{
  Serial.println("THIEF START");
 // convert to string
  char buf[32];
  String strVolt;
 // String strVolt = dtostrf( bat_volt, 4, 1, buf);
  strVolt=100;
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
  Serial.println("THIEF END");
}


