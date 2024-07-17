#include <Arduino.h>
#include <U8x8lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif

U8X8_SSD1306_128X32_UNIVISION_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE, /* clock=*/ SCL, /* data=*/ SDA);   // pin remapping with ESP8266 HW I2C

#include <SoftwareSerial.h>

// Create a SoftwareSerial object
//SoftwareSerial mySerial(10, 11); // TX, RX
SoftwareSerial mySoftwareSerial(10, 11); // TX, RX 핀 설정

void setup() {
  // Start the hardware serial communication
  Serial.begin(9600);
  // Start the software serial communication
  mySoftwareSerial.begin(9600);
  // Initial message
  Serial.println("Ready to communicate via software serial!");

  u8x8.begin();
  u8x8.setPowerSave(0);
  Serial.begin(9600);
}

void loop() {
  // PC에서 아두이노 IDE 시리얼 모니터(a90b) -> 아두이노 -> terra term (PC)
  String sub_uga = "";
  if (mySoftwareSerial.available()>0){
    String uga = Serial.readStringUntil('\n');
    // String receivedChar = mySoftwareSerial.read();
    int start = uga.indexOf('a');  // 'a'의 인덱스번호 = 0
    int end = uga.indexOf('b');
    // substring 하기
    sub_uga = uga.substring(start+1,end);
    mySoftwareSerial.println(sub_uga);// 수신된 데이터 처리
  }
  if (mySoftwareSerial.available()>0) {
    String uga = mySoftwareSerial.readStringUntil('\n');
    // String receivedChar = mySoftwareSerial.read();
    int start = uga.indexOf('a');  // 'a'의 인덱스번호 = 0
    int end = uga.indexOf('b');
    // substring 하기
    sub_uga = uga.substring(start+1,end);
    Serial.println(sub_uga);// 수신된 데이터 처리
  }
//  // Check if data is available on the software serial port
//  if (mySerial.available()) {
//    char dataFromDevice = mySerial.read();
//    Serial.write(dataFromDevice); // Send data to the serial monitor
//  }
}
