# Motors
here is the circuts & codes for sevral types of the motors
## Servo Motor
The servo motor rotates in a certain angle between 0 & 180
The servo motor consist of regular DC motor with electronic control board & some gears to maintain its angle position
![alt text](https://www.jameco.com/Jameco/workshop/Howitworks/how-servo-motors-work-fig2.jpg)
The servo motor doesn't need a driver since there is a control board inside it, so it directly connect to the arduino
the servo motor has 3 pins:
* 5v pin : connected to the postive pole of a 5v battery or to the 5v pin of the arduino
* Gound pin : connected to negative pole of a battery or to the ground pin of the arduino
* Signal pin : connected to one of the PWM output pins of the arduino
here is the circuit for the servo motor controlled by a potentiometer
![alt text](https://github.com/Maashn5/Motors/blob/main/Servo_test/servo%20motor%20movement.png)
& here is the code 
```c++
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
```
## Stepper Motor
## Brushless Motor
