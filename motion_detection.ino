int trig=12;
//int echo=10;
float dur;
int dis=12;
void setup(){

  pinMode(trig,OUTPUT);
  //pinMode(echo,INPUT);
  
}
void loop()
{
  digitalWrite(trig,LOW);
  delay(2000);
  digitalWrite(trig,HIGH);
  delay(1000);
  digitalWrite(trig,LOW);
  //dur=pulseIn(echo,HIGH);
  //dis=(0.342*dur)/2;
}  
  

