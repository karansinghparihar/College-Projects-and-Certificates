#include <LiquidCrystal.h>//adding liquidcrystal class along with all its properties in that program.

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //RS,E,D4,D5,D6,D7 OF LCD MODULE. 

int open(int);
int close(int);

int pir=13;//digital output from pir to pin13.
int pirval;
int openp=0;//yeha hold karega vo value jitni baar open function call hoga.
int closep=0;//yeha hold karega vo value jitni baar close function call hoga.
int varforopen=0;
int varforclose=0;
int count1=0;
int count2=0;
int countp=0;

void setup() {
lcd.begin(16,2);
Serial.begin(9600);
pinMode(9,OUTPUT);
pinMode(6,OUTPUT);
pinMode(pir,INPUT);
digitalWrite(pir,LOW);//pin 13 ko input milega pir sensor se.
}

void loop() {
 pirval=digitalRead(pir);//stores pin13 value
  analogWrite(9,0);//9 for clockwise motion
  analogWrite(6,0);//6 for anticlockwise motion

 if(pirval==HIGH)//it executes when person is near pir or door
 {
  if(count1==0)
  {
     lcd.setCursor(0, 0);
     lcd.print("gate is openning");
  openp=open(varforopen);//when person is near pir than it opens the gate in 5 sec->motor running in clockwise direction for 5 sec and than it stops.
  varforopen++;//jisse jitni baar open function execute ho utni hi baar varforopen increment ho jo aage kaam aayega no. of persons ko count karne main.
  count1++;//increment in that value so open() executes only 1 time.
  count2--;//for executing close()when second person in reaches at door.
  }
 }
  
 if(pirval==LOW)//it executes when person is away from pir or door
 {
  if(count2==0)
  {
    lcd.setCursor(0,0);
    lcd.print("gate is closing");
  closep=close(varforclose);//when person move away from pir than it closes the gate in 5 sec->motor running in anticlockwise direction for 5 sec and than stops.
  varforclose++;//jisse jitni baar close function execute ho utni hi baar varforclose increment ho jo aage kaam aayega no. of persons ko count karne main.
  count2++;//increment in that value so close() executes only 1 time.
  count1--;//for executing ope()when second person in reaches at door.
  }
}
 if(openp>0&&closep>0)//only executes when both open(),close()occur one after the other ->this person in entering and leaving the door->than count that as 1 person and so on.
 {
  countp=(openp+closep)/2;
  lcd.setCursor(0,1);
  lcd.print("TOTAL PEOPLES");
  lcd.print(countp);
 }
 }
int open(int o)
{  
  o=varforopen;
  analogWrite(9,255);
  analogWrite(6,0);
  delay(2000);
  o++;
  return o;
  }
int close(int c)
{ 
  c=varforclose;
  analogWrite(9,0);
  analogWrite(6,255);
  delay(2000);
  c++;
  return c;
 }


