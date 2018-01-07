#include<SoftwareSerial.h>//to include SoftwareSerial class file
void motc();
void mota();
void motoff();
String t;
int motcl=11;
int motacl=10;
SoftwareSerial mySerial(9,10);//to make pin 9,10 as Rx,Tx respectively for serial communication between bluetooth module and arduino
void setup()
{ motoff();
  Serial.begin(9600);//baud rate 9600 between serial monitor and arduino serial ports 0,1
  mySerial.begin(9600);//baud rate 9600 between bluetooth module and arduino serial ports 9,19
  delay(1000);
  pinMode(motcl,OUTPUT);
  pinMode(motacl,OUTPUT);
}
void loop()
{
if(mySerial.available()>0)//checks if String as serial data is available at pin 9 from bluetooth module module
{ 
  Serial.println("transfers data from bluetooth module to arduino as 1,2,3.... FOR VARIOUS IF CONDITION");//print on serial monitor
    t=mySerial.readString();//read that serial data complete String at a time at pin 9 and 10 and than stored that data in variable t
    mySerial.flush();//hold the program until we entered all input on pin 9 and 10
    
    Serial.print("entered String is = ");
    Serial.println(t); //print the value of String t or the message from mobile on serial monitor
   if(t=="on")//if message from mobile is on than this block is executes and motc() called
  {
  Serial.println("if condition block");   
  motc();
  delay(5000);
  
  }
  else if(t=="off")//if message from mobile is off than this block executes and mota() called
  {
   Serial.println("elseif condition block");    
  mota();
  delay(5000);
  
  }
  else//if message from mobile is anything but other than on and off than this block executes and motor remains off 
  {Serial.println("else condition block");   
  motoff();
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

