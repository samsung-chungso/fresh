const int BUZZER = 10;

void setup() {  
  tone(BUZZER, 262);  
  delay(1000);
  noTone(BUZZER);
  Serial.begin(9600);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  if(Serial.available()>0){
    char c = Serial.read();
    if(c=='a'){
      tone(BUZZER, 440);    // 'a'를 입력받으면 440Hz 톤을 출력
      delay(1000);
      noTone(BUZZER);
    }
    else if (c=='b'){
      tone(BUZZER, 523);    // 'b'를 입력받으면 523Hz 톤을 출력
      delay(1000);
      noTone(BUZZER);
    }
  }
}
