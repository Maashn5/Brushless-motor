#include <Servo.h>
Servo myservo;

double Voltage; 
double angle  ;


void setup() {
  // put your setup code here, to run once:
myservo.attach(3) ;
  
 
}

void loop() {
  // put your main code here, to run repeatedly:
  // initial position
  
  Voltage= analogRead(A1); // reading the voltage in the potentiometer
  angle=map(Voltage, 0,1023,0,180); // converting the voltage to angle between 0 & 180
  
  
  myservo.write(angle); // change the the servo angle
  
  
  
}
