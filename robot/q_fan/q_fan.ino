int A_IA = 10;   
int A_IB = 9;
bool button_state = false;
bool prev_button_state = false;
int count = 0;

void setup() {
  Serial.begin(115200);
  pinMode(A_IA,OUTPUT);
  pinMode(A_IB,OUTPUT);
  pinMode(12, INPUT_PULLUP);
}

void loop() {
  button_state = digitalRead(12);
  Serial.println(button_state);
  if (count==4){
    count=0;
  }
  if ((button_state == false) && (prev_button_state == true)){
    count= count +1;
  }
  if (count == 0){
    Serial.println(count);
    analogWrite(A_IA,0);
    analogWrite(A_IB,0);
  }
  else if (count == 1){
    Serial.println(count);
    analogWrite(A_IA,100);
    analogWrite(A_IB,0);
  }
  else if (count == 2){
    Serial.println(count);
    analogWrite(A_IA,160);
    analogWrite(A_IB,0);
  }
  else if (count == 3){
    Serial.println(count);
    analogWrite(A_IA,200);
    analogWrite(A_IB,0);
  }
  else if (count ==4){
    Serial.println(count);
    count= 0;
  }
  prev_button_state = button_state;
  delay(55);
}
