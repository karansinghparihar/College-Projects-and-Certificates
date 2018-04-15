/*
LED Dimmer
by Genius Arduino Programmer
2012

Controls the brightness of an LED on pin D9
based on the reading of a photocell on pin A0

This code is in the Public Domain
*/

// name analog pin 0 a constant name
const int analogInPin = A0; 

// name digital pin 9 a constant name
const int LEDPin = 9; 

//variable for reading a photocell
int photocell;

void setup() {
  Serial.begin(9600);

}

void loop() {
  //read the analog in pin and set the reading to the photocell variable
  photocell = analogRead(analogInPin);
 
  //print the photocell value into the serial monitor
 Serial.print("Photocell = " );                       
 Serial.println(photocell); 
  
  //control the LED pin using the value read by the photocell
  analogWrite(LEDPin, photocell);
  
  //pause the code for 1/10 second
  //1 second = 1000
  delay(100);  
}

