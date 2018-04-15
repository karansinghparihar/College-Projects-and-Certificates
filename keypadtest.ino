#include<LiquidCrystal.h>
#include<Keypad.h>
int ir1=2,alarm1=3,light1=4;
int ir2=5,alarm2=6;//LIGHT NOT INCLUDED IN ROOM2 AS ALL PINS ARE FINISHED.
void secure();
void notsecure();

void fear1()
{
  //esp8266.println("GET request for room1 parameter to reciever.php");
  Serial.println("value of ir1 change");
  }
  void fear2()
{
  //esp8266.println("GET request for room2 parameter to reciever.php");
  Serial.println("value of ir2 change");
  }
char verify[10];
char real[]={'1','2','3','4','5','6','\0'};
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};
int i=0;

char password[10];
byte rowPins[ROWS] = {10, 9, 8, 7}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {13, 12, 11}; //connect to the column pinouts of the keypad

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
// set up the LCD's number of columns and rows:
Serial.begin(9600);
digitalWrite(ir1,HIGH);
digitalWrite(alarm1,HIGH);
digitalWrite(light1,HIGH);

digitalWrite(ir2,HIGH);
digitalWrite(alarm2,HIGH);

lcd.begin(16, 2);
lcd.setCursor(0,0);
lcd.println("YOUR HOME : ");
lcd.setCursor(0,1);
lcd.println("SECURED");
delay(1000);
lcd.clear();
lcd.setCursor(0,0);
lcd.println("ENTER PASSWORD :");
lcd.setCursor(0,1);

pinMode(ir1,INPUT);
pinMode(alarm1,OUTPUT);
pinMode(light1,OUTPUT);

pinMode(ir2,INPUT);
pinMode(alarm2,OUTPUT);

}

void loop()
{
  
char key = keypad.getKey();

if (key!=NO_KEY && i<6) 
{

lcd.print("*");
 password[i]=key;
 i++;
}

if(i==6)
{
  password[i]='\0';

//int j=i;
    lcd.clear();
   /* lcd.setCursor(0,0);
    lcd.print("ENTERED PASSWORD = ");
    for(int k=0;k<=i;k++)
    {  
     lcd.print(password[k]);
    }
     Serial.println("\n");
   
    */
    

  
  int r= memcmp(real,password,7);
 if(r==0)
 {
     lcd.clear();
      lcd.setCursor(0,0);
  lcd.println("CORRECT PASSWORD");
   lcd.setCursor(0,1);
  notsecure();
  }  
  else if(r!=0)
  {
   //while(i<3)--->3 times incorrect password is allowed to type.
     lcd.clear();
      lcd.setCursor(0,0);
lcd.println("INCORRECT PASSWORD"); 
 lcd.setCursor(0,1);
 /*delay(1000);
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.println("WAIT FOR :"); 
 lcd.setCursor(0,1);  
 lcd.println("5 SECONDS"); */
secure();
    
    }
 
    
    i++;
}


  
}
void secure()
{
  lcd.println("SECURITYACTIVATE");
 int sense1= digitalRead(ir1);
  //Serial.print("BEFORE interrupt ir value = ");
  //Serial.println(sense1);
  digitalWrite(alarm1,HIGH);
  digitalWrite(light1,HIGH);
  //delay(5000);
  
  attachInterrupt(digitalPinToInterrupt(ir1),fear1,CHANGE);
  //Serial.print("AFTER interrupt ir value = ");
 // Serial.println(sense1);
  //delay(5000);
  int sense2= digitalRead(ir2);
  digitalWrite(alarm2,HIGH);
  attachInterrupt(digitalPinToInterrupt(ir2),fear2,CHANGE);
  
  
  
  
 
}
void notsecure()  
{
  lcd.println("SECURITYDEACTIVATE");
  digitalWrite(ir1,LOW);
  digitalWrite(alarm1,LOW);
  digitalWrite(light1,LOW);
   digitalWrite(ir2,LOW);
  digitalWrite(alarm2,LOW);
  
}


