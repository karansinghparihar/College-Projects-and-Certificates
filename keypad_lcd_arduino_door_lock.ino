
#include<LiquidCrystal.h>
#include<Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};
int i=0,j=0,ir=13,alarm=14,light=15;
char p;
char password[10];//not authorised otherwise. 
String verify;
void secure();
void notsecure();
void fear()
{
  Serial.println("esp8266 GET request\n");
  }
byte rowPins[ROWS] = {10, 9, 8, 7}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {13, 12, 11}; //connect to the column pinouts of the keypad

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

//{
//esp8266.print("GET /reciever.php?room1=NOTSECURE HTTP/1.1\r\nHost: 192.168.1.1\r\n");
//}

void setup() {
  // set up the LCD's number of columns and rows:
  //Serial.begin(9600);
  

lcd.begin(16, 2);
lcd.setCursor(0,0);

}

void loop() {



   char key = keypad.getKey();
   p=key;
    if (key=!NO_KEY){
    //lcd.setCursor(0,1);
    lcd.print(p);
    i++;
   //  lcd.setCursor(i, j);
      password[i]=key;
    }
   // else if(key == '#')
    //{
     // i++;
      //password[i]='\0';
      //for(int k=0;k<=i;k++)
    //{  verify[k]=password[k];}
      
      //}
 /*if(verify=="12345")
 {
  notsecure();
 }  
  if(verify!="12345")
 {
 secure();
 }        
*/
}

void secure()
{
  digitalWrite(ir,HIGH);
  digitalWrite(alarm,HIGH);
  digitalWrite(light,HIGH);
  delay(5000);
  ir=LOW;
  attachInterrupt(digitalPinToInterrupt(ir),fear,CHANGE);
  delay(5000);
  
 
}
void notsecure()  
{
  digitalWrite(ir,LOW);
  digitalWrite(alarm,LOW);
  digitalWrite(light,LOW);
}




























