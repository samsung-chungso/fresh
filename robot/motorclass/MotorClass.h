#ifndef MOTOR_CLASS_H
#define MOTOR_CLASS_H

class MotorClass{
  public:
    MotorClass(int ia_pin, int ib_pin);
    void start();
    void turn_on();
    void turn_off();
    void forward();
    void backward();

    int ia_pin_num;
    int ib_pin_num;
  private:
    
};
#endif
