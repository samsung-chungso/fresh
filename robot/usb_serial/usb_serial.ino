#include <SoftwareSerial.h>

// Create a SoftwareSerial object
SoftwareSerial mySerial(10, 11); // TX, RX

void setup() {
  // Start the hardware serial communication
  Serial.begin(9600);
  // Start the software serial communication
  mySerial.begin(9600);
  // Initial message
  Serial.println("Ready to communicate via software serial!");
}

void loop() {
  // PC에서 아두이노 IDE 시리얼 모니터(a90b) -> 아두이노 -> terra term (PC)
  if (mySerial.available()){
    String uga = Serial.readStringUntil('\n');
    mySerial.println(uga);
  }
//  // Check if data is available on the software serial port
//  if (mySerial.available()) {
//    char dataFromDevice = mySerial.read();
//    Serial.write(dataFromDevice); // Send data to the serial monitor
//  }
}
