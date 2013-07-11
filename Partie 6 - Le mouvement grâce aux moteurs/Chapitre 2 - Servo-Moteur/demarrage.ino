#include <Servo.h>

Servo monServo;

void setup()
{
   monServo.attach(2, 1000, 2000);
   monServo.write(90);
}
void loop()
{

}
