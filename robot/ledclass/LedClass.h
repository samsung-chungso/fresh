#ifndef LED_CLASS_H
#define LED_CLASS_H

class LedClass{
public:
  LedClass(int pin);  // def __init__(self): 생성자
  void begin();
  void turn_on();
  void turn_off();

  int pin_num;  // class 안의 어디서든 다 쓰일 수 있다.
private:
};
#endif
