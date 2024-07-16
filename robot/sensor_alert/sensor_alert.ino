// HC-SR04 초음파 센서 핀 정의
const int trigPin = 9;
const int echoPin = 10;

// 경고를 위한 LED 또는 부저 핀 정의
const int alertPin = 13;

// 거리 및 시간 기준 정의
const long detectionDistance = 10; // 감지 거리 (단위: cm)
const long requiredDuration = 3000; // 물체가 머물러야 할 시간 (단위: ms)

// 변수 초기화
long duration;
int distance;
unsigned long detectionStartTime = 0;
bool objectDetected = false;

void setup() {
  // 핀 설정
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(alertPin, OUTPUT);

  // 시리얼 통신 시작
  Serial.begin(9600);
}

void loop() {
  // 초음파 센서 트리거 핀에 10마이크로초 펄스 보내기
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // 에코 핀에서 펄스 길이 측정
  duration = pulseIn(echoPin, HIGH);

  // 거리를 cm 단위로 계산
  distance = duration * 0.034 / 2;

  // 거리 출력 (디버깅용)
  Serial.print("Distance: ");
  Serial.println(distance);

  // 물체 감지 여부 확인
  if (distance < detectionDistance) {
    if (!objectDetected) {
      // 처음 감지한 경우 시간 기록
      detectionStartTime = millis();
      objectDetected = true;
    } else {
      // 감지된 상태에서 경과 시간 확인
      if (millis() - detectionStartTime >= requiredDuration) {
        // 경과 시간이 기준 시간을 넘으면 경고 신호
        digitalWrite(alertPin, HIGH);
      }
    }
  } else {
    // 물체가 감지 거리 밖에 있으면 경고 해제 및 상태 초기화
    digitalWrite(alertPin, LOW);
    objectDetected = false;
  }

  // 짧은 지연
  delay(50);
}
