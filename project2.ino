#include <LiquidCrystal.h> // includes the LiquidCrystal Library 
#include <Keypad.h>
#include <SoftwareSerial.h>
#define buzzer 8
SoftwareSerial mySerial(2,3);
int pir =12;
int screenOffMsg =0;
String password="1234";
String tempPassword;
boolean activated = false; // State of the alarm
boolean isActivated;
boolean activateAlarm = false;
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
byte rowPins[ROWS] = {4,5,6,7}; //Row pinouts of the keypad
byte colPins[COLS] = {8,9,10,11}; //Column pinouts of the keypad
Keypad myKeypad = Keypad( makeKeymap(keyMap), rowPins, colPins, ROWS, COLS); 
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7) 

void setup() { 
  lcd.begin(16,2); 
Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(12, INPUT);
  pinMode(13, OUTPUT);

}

void loop() {
  
  if (activateAlarm) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Alarm will be");
    lcd.setCursor(0,1);
    lcd.print("activated in");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Alarm Activated!");
    //initialDistance = getDistance();
    activateAlarm = false;
    alarmActivated = true;
  }
 
    if (alarmActivated == true){
     int PIR = digitalRead(12);
      if (PIR==HIGH)
      {
        tone(buzzer, 1000); // Send 1KHz sound signal 
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.println("Sending message to");
        lcd.setCursor(0,1);
        Serial.println("pir high");
        lcd.println("91****");
        delay(1000);
        lcd.clear();
       /* mySerial.println("AT+CMGF=1"); // set the SMS mode to text
delay(500);
mySerial.write("AT+CMGS=");
mySerial.write(34); //ASCII of "
mySerial.write("+917611942803");
mySerial.write(34);
mySerial.write(13);
mySerial.write(10);
delay(500);
mySerial.println("hello"); //this is the message to be sent
delay(2500);

mySerial.write(26);
mySerial.write(13);
mySerial.write(10);//Ascii code of ctrl+z to send the message
delay(500);
Serial.println("message end");
*/
/*mySerial.write("ATD+917611942803");
mySerial.write(34);
mySerial.write(13);
mySerial.write(10);
delay(5000);
mySerial.write("ATH");
mySerial.write(34);
mySerial.write(13);
mySerial.write(10);
*/
Serial.println("call start");
mySerial.write("ATD +919602820047;\r");//Phone number you want to call
 //delay(5000);
 //mySerial.print("ATH;\r");
 Serial.println("call end");
enterPassword();
}
 }
  if (!alarmActivated) {
    if (screenOffMsg == 0 ){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("A - Activate");
      lcd.setCursor(0,1);
      lcd.print("B - Change Pass");
      screenOffMsg = 1;
    }
    keypressed = myKeypad.getKey();
     if (keypressed =='A'){        //If A is pressed, activate the alarm
      tone(buzzer, 1000, 200);
      activateAlarm = true; 
digitalWrite(13,HIGH);
Serial.println("AAAAAAAAAA");
    }
    else if (keypressed =='B') {
      lcd.clear();
      
      int i=1;
      tone(buzzer, 2000, 100);
      tempPassword = "";
      lcd.setCursor(0,0);
      lcd.print("Current Password");
      lcd.setCursor(0,1);
      lcd.print(">");
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
         i++;
     
               

                   Serial.println(keypressed);

         tone(buzzer, 2000, 100);
        }
      }
      if (i > 5 || keypressed == '#') {
        tempPassword = "";
        i=1;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Current Password");
        lcd.setCursor(0,1);
        lcd.print(">"); 
      }
      if ( keypressed == '*') {
        i=1;
        tone(buzzer, 2000, 100);
        if (password == tempPassword) {
          tempPassword="";
          digitalWrite(13,HIGH);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Set New Password");
          lcd.setCursor(0,1);
          lcd.print(">");
          while(passChangeMode) {
            keypressed = myKeypad.getKey();
            if (keypressed != NO_KEY){
              if (keypressed == '0' || keypressed == '1' || keypressed == '2' || keypressed == '3' ||
                  keypressed == '4' || keypressed == '5' || keypressed == '6' || keypressed == '7' ||
                  keypressed == '8' || keypressed == '9' ) {
                tempPassword += keypressed;
                lcd.setCursor(i,1);
                lcd.print(keypressed);
                i++;
                Serial.println(keypressed);
                tone(buzzer, 2000, 100);
              }
            }
            if (i > 5 || keypressed == '#') {
              tempPassword = "";
              i=1;
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
              digitalWrite(13,LOW);
            }            
          }
        }
      }
    }
   }
 }
}
void enterPassword() {
  mySerial.println("AT+CMGF=1"); // set the SMS mode to text
delay(500);
mySerial.write("AT+CMGS=");
mySerial.write(34); //ASCII of "
mySerial.write("+919783952043");
mySerial.write(34);
mySerial.write(13);
mySerial.write(10);
delay(1000);
mySerial.println("hello"); //this is the message to be sent
//delay(2500);
mySerial.write(26);
mySerial.write(13);
mySerial.write(10);//Ascii code of ctrl+z to send the message
delay(500);
//while(1);
  int k=5;
  tempPassword = "";
  activated = true;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" * ALARM * ");
  lcd.setCursor(0,1);
  lcd.print("Pass>");
      while(activated) {
      keypressed = myKeypad.getKey();
      if (keypressed != NO_KEY){
        if (keypressed == '0' || keypressed == '1' || keypressed == '2' || keypressed == '3' ||
            keypressed == '4' || keypressed == '5' || keypressed == '6' || keypressed == '7' ||
            keypressed == '8' || keypressed == '9' ) {
          tempPassword += keypressed;
          lcd.setCursor(k,1);
          lcd.print(keypressed);
          k++;
          Serial.println(keypressed);
          
        }
      }
      if (k > 9 || keypressed == '#') {
        tempPassword = "";
        k=5;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(" * ALARM * ");
        lcd.setCursor(0,1);
        lcd.print("Pass>");
      }
      if ( keypressed == '*') {
        if ( tempPassword == password ) {
          activated = false;
          alarmActivated = false;
          noTone(buzzer);
          Serial.println(keypressed);
          Serial.println("deactivare");
          digitalWrite(13,LOW);
          screenOffMsg = 0; 
        }
        else if (tempPassword != password) {
          lcd.setCursor(0,1);
          lcd.print("LOL!");
          delay(1000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print(" * ALARM * ");
          lcd.setCursor(0,1);
          lcd.print("Pass>");
        }
      }    
    }
}
