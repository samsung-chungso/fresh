int IR1 = 3;
int IR2 = 4;

void setup(){
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  Serial.begin(115200);
}
void loop(){
  int IRsensor1 = digitalRead(IR1);
  int IRsensor2 = digitalRead(IR2);
//  Serial.println(IRsensor1);
//  Serial.println(IRsensor2);
  if(IRsensor1==LOW){
    Serial.println("IR1 completed");
  }
  else if(IRsensor2==LOW){
    Serial.println("IR2 completed");
  }
}
