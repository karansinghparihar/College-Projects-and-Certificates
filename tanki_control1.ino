void motc();
void mota();
void motoff();
int t;
int motcl=11;
int motacl=10;
void setup() {
  Serial.begin(9600);
  pinMode(motcl,OUTPUT);
  pinMode(motacl,OUTPUT);
  }
void loop() {
  if(Serial.available()>0)
  {
    t=Serial.read();
    Serial.flush();
    t=t-48;
    Serial.print("val = ");
    Serial.println(t);
   switch(t)
  {
  case 1:
  Serial.println("if condition block");
  motc();
  delay(5000);
  t=0;//to remove t=1
  break;
  case 2:
  Serial.println("elseif condition block");    
  mota();
  delay(5000);
  t=0;//to remove t=2
  break;
  default :
  Serial.println("else condition block");   
  motoff();
  delay(5000);
  break;
  }
  }
}
void motc()
{Serial.println("motc block");   
  analogWrite(motcl,255);
  analogWrite(motacl,0);
  delay(5000);
  motoff();
}
void mota()
{Serial.println("mota block");
  analogWrite(motcl,0);
  analogWrite(motacl,255);
  delay(5000);
   motoff();
  }
void motoff()
{Serial.println("motoff block");
  analogWrite(motcl,0);
  analogWrite(motacl,0);
}

