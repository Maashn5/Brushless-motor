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
