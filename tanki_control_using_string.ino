void motc();
void mota();
void motoff();
String t;
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
    t=Serial.readString();
    Serial.flush();
    Serial.print("You entered = ");
    Serial.println(t);
    
  
  if(t=="on")
  {
  Serial.println("if condition block");   
  motc();
  delay(5000);
  
  }
  else if(t=="off")
  {
   Serial.println("elseif condition block");    
  mota();
  delay(5000);
  
  }
  else
  {Serial.println("else condition block");   
  motoff();
  delay(5000);
  }
}}
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

