const int sensorPin = A0; // 아날로그 입력 핀 정의
const float alpha = 0.1;  // 필터 계수 (0.0 - 1.0 사이 값)
float filteredValue = 0;  // 필터링된 값 초기화

void setup() {
  Serial.begin(9600);  // 시리얼 통신 시작
  filteredValue = analogRead(sensorPin);  // 초기 필터링 값 설정
}

void loop() {
  int sensorValue = analogRead(sensorPin);  // 센서 값 읽기
  filteredValue = alpha * sensorValue + (1 - alpha) * filteredValue;  // 로우패스 필터 적용

  Serial.print("Raw Value: ");
  Serial.print(sensorValue);
  Serial.print("\tFiltered Value: ");
  Serial.println(filteredValue);

  delay(50);  // 짧은 지연
}
