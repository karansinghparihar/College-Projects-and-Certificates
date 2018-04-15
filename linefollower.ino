int rightf=9;
int rightr=6;
int leftf=5;
int leftr=3;
int left=13;
int right=12;
int Left=0;
int Right=0;
void LEFT (void);
void RIGHT (void);
void STOP (void);
void setup()
{
  pinMode(rightf,OUTPUT);
  pinMode(rightr,OUTPUT);
  pinMode(leftf,OUTPUT);
  pinMode(leftr,OUTPUT);
  pinMode(left,INPUT);
  pinMode(right,INPUT);
  digitalWrite(left,HIGH);
  digitalWrite(right,HIGH);
}
void loop() 
{
  Left=digitalRead(left);
  Right=digitalRead(right);
  if(Left==1 && Right==1)
  MOTION();
  if(Left==0 && Right==1)
  LEFT();
  if(Right==0 && Left==1)
  RIGHT();
  if(Left==0 && Right==0)
  STOP();

}
void LEFT (void)
{
  analogWrite(rightf,255);
  analogWrite(rightr,0); 
  analogWrite(leftf,0);
  analogWrite(leftr,30);
}
void RIGHT (void)
{
   analogWrite(rightf,0);
   analogWrite(rightr,30);
   analogWrite(leftf,255);
   analogWrite(leftr,0);
}
void STOP (void)
{
analogWrite(rightf,0);
analogWrite(rightr,0);
analogWrite(leftf,0);
analogWrite(leftr,0);
}

void MOTION(void)
{
analogWrite(rightf,255);
analogWrite(rightr,255);
analogWrite(leftf,255);
analogWrite(leftr,0);
}
  
  















