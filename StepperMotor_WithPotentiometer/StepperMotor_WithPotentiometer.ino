#include <Stepper.h>

#define steps 200


Stepper StepperMotor(steps,2,3,4,5);

double Voltage;
double NextStep;
double PastStep=0;
double Angle;

void setup()
{
  StepperMotor.setSpeed(60);
}

void loop()
{
  Voltage = analogRead(A3);
  
  NextStep= map(Voltage,0,1023,0,200);
    
  Angle= NextStep - PastStep;
  StepperMotor.step(Angle);
  PastStep=NextStep;
  delay(2000);
}
