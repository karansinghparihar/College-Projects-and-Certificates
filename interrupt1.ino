volatile int led=2;
int i=1;
void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(led,INPUT);
  attachInterrupt(digitalPinToInterrupt(led),ledstatus,CHANGE);

}

void loop() {
  Serial.print(i);
  Serial.println(" = loop");
if(led==HIGH)
 {
  led=LOW;
 }

  i++;
  delay(1000);
  

}
void ledstatus()
{
  if(led==LOW)
  {
    Serial.println("now led is high");
    digitalWrite(13,HIGH);
    led=HIGH;
  }
 /* else
  {
    Serial.println("now led is low");
    digitalWrite(13,LOW);
  }*/
}

