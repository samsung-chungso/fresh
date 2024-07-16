#include "MotorClass.h"
MotorClass motor1(10,9);
MotorClass motor2(13,8);

void setup() {
  // put your setup code here, to run once:
  motor1.start();

}

void loop() {
  // put your main code here, to run repeatedly:
  motor1.turn_on();
  delay(1000);
  motor1.turn_off();
  delay(1000);
  motor1.forward();
  delay(1000);
  motor1.backward();
  delay(1000);
}
