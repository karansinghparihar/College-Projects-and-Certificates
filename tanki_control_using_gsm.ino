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
SoftwareSerial mySerial(9,10);//to make pin 9,10 as Rx,Tx respectively for serial communication between GSM and arduino
void setup()
{ motoff();
  Serial.begin(9600);//baud rate 9600 between serial monitor and arduino serial ports 0,1
  Serial.begin(9600);//baud rate 9600 between GSM and arduino serial ports 9,19
  delay(1000);
  pinMode(motcl,OUTPUT);
  pinMode(motacl,OUTPUT);
}
void loop()
{
  if(Serial.available()>0)//checks if serial data available at 0 pin from serial monitor
  {
    i=Serial.read();
    Serial.flush();
  switch(i)//reads that data one byte at a time and than used for switch case
  {
    case 's'://s-->to invoke sen_to_mobile
    Serial.println("case s");
    send_to_mobile();
    Serial.println("now we break case s");
    break;
    case 'r'://r-->to invoke send_from_mobile
    Serial.println("case r");
    send_from_mobile();
    Serial.println("now we break case r");
    break;
  }
}
if(mySerial.available()>0)//checks if serial data is available at pin 9 from GSM module
{
  Serial.println("transfers data from GSM to arduino as 1,2,3.... FOR SWITCH CASE");//print on serial monitor
    t=mySerial.read();//read that serial data one byte at a time at pin 9 and 10 and than stored that data in variable t
    mySerial.flush();//hold the program until we entered all input on pin 9 and 10
    t=t-48;//to get same value as input not ASCI
    Serial.print("val of t = ");
    Serial.println(t); //print the value of t or the sms from mobile on serial monitor
    switch(t)
  {
  case 1://if sms from mobile is 1 this case executes and motor starts in clockwise direction
  motc();//to call function to start motor in clockwise direction
  delay(5000);
  break;
  case 2://if sms from mobile is 2 this case executes and motor starts in anticlockwise direction
  mota();//to call function to stop motor by moving in anticlockwise direction
  delay(5000);
  break;
  default ://when sms is anything except 1 or 2 than this case executes and motor remains off 
  motoff();//to call so that motor is not moving in either direction
  delay(5000);
  break;
  }
 }
}
void send_to_mobile()
{Serial.println("send to mobile starts");
  Serial.println("AT+CMGF=1");//first command line on gsm to create text mode
  delay(1000);
  Serial.println("AT+CMGS=\"+7014533381\""); //second command line on gsm to send sms to the entered mobile number
  delay(1000);
  Serial.print("sending to mobile from arduino through GSM modulE");//sms which send to mobile
  delay(1000);
  Serial.println((char)26);// to send the above written sms (char)26-->ctrl+z
  delay(1000);
  Serial.println("send to mobile ends");
  }
void send_from_mobile()
{Serial.println("send from mobile starts");
  Serial.println("AT+CNMI=2,2,0,0,0");//next command after ctrl+z is to make gsm for recieving message from mobile which further transmit to pin 9 at Serial.available()
  delay(1000);
  Serial.println("send from mobile ends");
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

