# Motors
here is the circuits & codes for sevral types of the motors
## Servo Motor
The servo motor rotates to a certain angle between 0 & 180
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
The stepper motor can be treated as an angle motor or as a speed motor
<br /> The stepper rotate in steps at a certain speed, each step has a particular angle for a certain motor
The stepper motor consist of colis & magnets , the coils turns on in a certain pattern to occur the steps
![alt text](https://www.amci.com/files/6215/9363/2691/stepper_current_4_steps.jpg)
The stepper motor require a driver to connect it to the arduino 
here is  the circuit of the stepper motor ( since the tinker cad doesn't have a stepper motor I did a alternative circuit)
![alt text](https://github.com/Maashn5/Motors/blob/main/StepperMotor_WithPotentiometer/stepper%20motor.png)
& here is the code for angle contolled by a potentiometer 
```c++
#include <Stepper.h>

#define steps 200


Stepper StepperMotor(steps,2,3,4,5); // declare a stepper motor & define its ports in the arduino

double Voltage;
double NextStep;
double PastStep=0;
double Angle;

void setup()
{
  StepperMotor.setSpeed(60); // setting the speed of the steps of the motor
}

void loop()
{
  Voltage = analogRead(A3); // reading the voltage of the potentiometer
  
  NextStep= map(Voltage,0,1023,0,200); // rescale the voltage into steps
    
  Angle= NextStep - PastStep; // take the difference between the old position & the new one 
  StepperMotor.step(Angle); // moving the stepper motor to its new position
  PastStep=NextStep; // now the new position become the new past position 
  delay(2000);
}
```
here is the code for speed contolled by a potentiometer
```c++
#include <Stepper.h>

#define steps 200


Stepper StepperMotor(steps,2,3,4,5); // declare a stepper motor & define its ports in the arduino

double Voltage;
double Speed;
void setup()
{
  
}

void loop()
{
  Voltage = analogRead(A3); // reading the voltage of the potentiometer
  
  Speed= map(Voltage,0,1023,0,100); // rescale the voltage into speed
  
  StepperMotor.setSpeed(Speed); // setting the speed of the steps of the motor  
  
  
  StepperMotor.step(steps/100); // step 1/100 of revolution 
  
  
}
```
## Brushless Motor
