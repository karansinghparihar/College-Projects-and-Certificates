#include<SoftwareSerial.h>//to include SoftwareSerial class file
void send_to_mobile();//prototype
void send_from_mobile();//prototype
void motc();
void mota();
void motoff();
int t;
char i;
int motcl=11;
int motacl=10;
SoftwareSerial mySerial(9,10);//to make pin 9,10 as Rx,Tx respectively for serial communication between bluetooth module and arduino
void setup()
{ motoff();
  Serial.begin(9600);//baud rate 9600 between serial monitor and arduino serial ports 0,1
  mySerial.begin(9600);//baud rate 9600 between bluetooth module and arduino serial ports 9,10
  delay(1000);
  pinMode(motcl,OUTPUT);
  pinMode(motacl,OUTPUT);
}
void loop()
{
if(mySerial.available()>0)//checks if serial data is available at pin 9 from bluetooth module module
{
  Serial.println("transfers data from bluetooth module to arduino as 1,2,3.... FOR SWITCH CASE");//print on serial monitor
    t=mySerial.read();//read that serial data one byte at a time at pin 9 and 10 and than stored that data in variable t
    mySerial.flush();//hold the program until we entered all input on pin 9 and 10
    t=t-48;//to get same value as input not ASCI
    Serial.print("val of t = ");
    Serial.println(t); //print the value of t or the message from mobile on serial monitor
    switch(t)
  {
  case 1://if message from mobile is 1 this case executes and motor starts in clockwise direction
  motc();//to call function to start motor in clockwise direction
  delay(5000);
  break;
  case 2://if message from mobile is 2 this case executes and motor starts in anticlockwise direction
  mota();//to call function to stop motor by moving in anticlockwise direction
  delay(5000);
  break;
  default ://when message is anything except 1 or 2 than this case executes and motor remains off 
  motoff();//to call so that motor is not moving in either direction
  delay(5000);
  break;
  }
 }
}
