#include "LedClass.h"
LedClass led1(13);
LedClass led2(10);

void setup(){  
  led1.begin();
  led2.begin();
}

void loop(){
  led1.turn_on();
  delay(1000);
  led2.turn_on();
  delay(1000);
  led1.turn_off();
  delay(1000);
  led2.turn_off();
}
