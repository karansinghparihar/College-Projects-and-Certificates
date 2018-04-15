int ac=8;
int light=11;
int tv=12;
int fan=13;



void setup() {
 pinMode(ac,OUTPUT);
 pinMode(light,OUTPUT);
 pinMode(tv,OUTPUT);
 pinMode(fan,OUTPUT);

}

void loop() {
  // if(+IPD) pin=11-->it affetcs the va;lue of light same goes for tv,fan,ac.
 digitalWrite(ac,HIGH);
 digitalWrite(light,HIGH);
digitalWrite(tv,HIGH);
digitalWrite(fan,HIGH);

}
