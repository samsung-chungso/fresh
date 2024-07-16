#include "Arduino.h"
#include "MotorClass.h"

MotorClass::MotorClass(int ia_pin, int ib_pin){
  ia_pin_num = ia_pin;
  ib_pin_num = ib_pin;
}

void MotorClass::start(){
  pinMode(ia_pin_num, OUTPUT);
  pinMode(ib_pin_num, OUTPUT);
}

void MotorClass::turn_on(){
  analogWrite(ia_pin_num, HIGH);
  analogWrite(ib_pin_num, HIGH);
}

void MotorClass::turn_off(){
  analogWrite(ia_pin_num, LOW);
  analogWrite(ib_pin_num, LOW);
}

void MotorClass::forward(){
  analogWrite(ia_pin_num, 120);
  analogWrite(ib_pin_num, 0);
}

void MotorClass::backward(){
  analogWrite(ia_pin_num, 0);
  analogWrite(ib_pin_num, 120);
}
