#include<SoftwareSerial.h>//to include SoftwareSerial class file
void motc();
void mota();
void motoff();
String t;
int motcl=3;
int motacl=5;
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
  Serial.println("transfers data from bluetooth module to arduino as 1,2,3.... FOR if conditions CASE");//print on serial monitor
    t=mySerial.readString();//read that serial data one byte at a time at pin 9 and 10 and than stored that data in variable t
    mySerial.flush();//hold the program until we entered all input on pin 9 and 1
    Serial.print("val of t = ");
    Serial.println(t); //print the value of t or the text message from mobile on serial monitor
    if(t=="on")//if text message from mobile is on this condition executes and motor starts in clockwise direction
  {
  motc();//to call function to start motor in clockwise direction
  delay(5000);
  mySerial.println("motor is on as text message recieve on mobile");
  delay(5000);
  }
  else if(t=="off")//if text message from mobile is off this condition executes and motor starts in anticlockwise direction
  {
  mota();//to call function to stop motor by moving in anticlockwise direction
  delay(5000);
  mySerial.println("motor is off as text message recieve on mobile");
  delay(5000);
  }
  else //when text message is anything except on or off than this condition executes and motor remains off 
  {
  motoff();//to call so that motor is not moving in either direction
  delay(5000);
  mySerial.println("INVALID INPUT so motor remains off as text message recieves at mobile");
  delay(5000);
  }
 }
}

void motc()
{Serial.println("motc block");   
  analogWrite(motcl,255);//clockwise rotation is full-->255 or 5v
  analogWrite(motacl,0);//anticlockwise rotation is zero-->0 or 0v
  delay(5000);
  motoff();//to stop the motor after given delay
}
void mota()
{Serial.println("mota block");
  analogWrite(motcl,0);//clockwise rotation is zero-->0 or 0v
  analogWrite(motacl,255);//anticlockwise rotation is full-->255 or 5v
  delay(5000);
   motoff();//to stop the motor after given delay
  }
void motoff()
{Serial.println("motoff block");
  analogWrite(motcl,0);//clockwise rotaion is zero
  analogWrite(motacl,0);//anticlockwise rotation is zero
}

