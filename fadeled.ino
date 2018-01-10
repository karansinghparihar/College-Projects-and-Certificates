int led_red=11;
int led_yellow=10;
int t=0;
int i; 
void setup() {
Serial.begin(9600);
pinMode(led_red,OUTPUT);
pinMode(led_yellow,OUTPUT);
  }

void loop() {
for(i=0;i<=255;i=i+25){
  analogWrite(led_red,i);
  delay(1000);
}
for(i=255;i>=0;i=i-25){
  analogWrite(led_red,i);


delay(1000);
}
/*if(Serial.available()>0)
{
t=Serial.read();
t=t-48;
Serial.print("wait for ");
Serial.print(t);
Serial.println(" secs" );

delay(t*1000);
}
analogWrite(led_yellow,LOW);
delay(1000);
for(i=0;i<=255;i=i+25){
  analogWrite(led_yellow,i);
}
for(i=255;i>=0;i=i-25){
  analogWrite(led_yellow,i);
}

*/
}
