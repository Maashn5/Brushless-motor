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
