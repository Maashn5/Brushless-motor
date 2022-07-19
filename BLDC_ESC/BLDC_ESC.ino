#include <Servo.h>
Servo ESC_BLDC;

double Voltage; 
double Speed  ;


void setup() {
  // put your setup code here, to run once:
ESC_BLDC.attach(6) ;
  
 
}

void loop() {
  // put your main code here, to run repeatedly:
 
  Voltage = analogRead(A1); // reading the voltage in the potentiometer
  Speed = map(Voltage, 0,1023,0,180); // converting the voltage to Speed between 0 & 180
  
  
  ESC_BLDC.write(Speed); // change the the BLDC Speed
  
  
  
}
