void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop(){
  if(Serial.available()>0){
//    String until = Serial.readStringUntil('\r');
    // r은 줄바꿈 아닌 전체 줄을 끝까지 읽는 것.
    String c = Serial.readStringUntil('\n');
    int first = c.indexOf('a');//index 0
    int second = c.indexOf('b'); //index 3

    // a 인덱스+1 부터 second-1 인덱스까지
    String c_str = c.substring(first+1, second);
    int a = c_str.toInt();
    a++;
    Serial.println(a);
  }
}
