int IR1 = 3;
int IR2 = 4;
//int LED = 13;
int A_IA = 11;
int A_IB = 10;
int B_IA = 6;
int B_IB = 5;
void setup(){
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
//  pinMode(LED,OUTPUT);
  Serial.begin(115200);
  pinMode(A_IA,OUTPUT);
  pinMode(A_IB,OUTPUT);
  pinMode(B_IA,OUTPUT);
  pinMode(B_IB,OUTPUT);
}
void loop(){
  int IRsensor1 = digitalRead(IR1);
  int IRsensor2 = digitalRead(IR2);
//  Serial.println(IRsensor1);
//  Serial.println(IRsensor2);
//  delay(1000);
//  analogWrite(A_IA,0);
//  analogWrite(A_IB,0);
//  analogWrite(B_IA,0);
//  analogWrite(B_IB,0);
//  if (IRsensor1 == 0 && IRsensor2 == 0){
//    analogWrite(A_IA,70);
//    analogWrite(A_IB,0);  
//    Serial.println("a");
//    analogWrite(B_IA,70);
//    analogWrite(B_IB,0);
//    Serial.println("b");
////    delay(1000);
//  }
if (IRsensor1 != 0 && IRsensor2 != 0){
    analogWrite(A_IA,0);
    analogWrite(A_IB,0);
    analogWrite(B_IA,0);
    analogWrite(B_IB,0);
  }
  else if (IRsensor1 == 0 && IRsensor2 != 0){
    analogWrite(A_IA,75);
    analogWrite(A_IB,0);
    analogWrite(B_IA,0);
    analogWrite(B_IB,0);
    delay(10);
  }
  else if(IRsensor1 != 0 && IRsensor2 == 0){
    analogWrite(A_IA,0);
    analogWrite(A_IB,0);
    analogWrite(B_IA,75);
    analogWrite(B_IB,0);
    delay(10);
  }
  else if(IRsensor1 == 0 && IRsensor2 == 0){
    analogWrite(A_IA,75);
    analogWrite(A_IB,0);
    analogWrite(B_IA,75);
    analogWrite(B_IB,0);
    delay(10);
  }
}
