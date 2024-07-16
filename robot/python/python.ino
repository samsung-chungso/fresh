#include <Arduino.h>
#include <U8x8lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif

U8X8_SSD1306_128X32_UNIVISION_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE, /* clock=*/ SCL, /* data=*/ SDA);   // pin remapping with ESP8266 HW I2C

void setup(void)
{
  /* U8g2 Project: SSD1306 Test Board */
  //pinMode(10, OUTPUT);
  //pinMode(9, OUTPUT);
  //digitalWrite(10, 0);
  //digitalWrite(9, 0);    
  
  /* U8g2 Project: KS0108 Test Board */
  //pinMode(16, OUTPUT);
  //digitalWrite(16, 0);  
  
  u8x8.begin();
  u8x8.setPowerSave(0);
  Serial.begin(9600);
  
  
}

void loop(void)
{
    String sub_uga="";
    String uga="";
    if(Serial.available() > 0){
    uga = Serial.readStringUntil('\n');
    int start = uga.indexOf('a');  // 'a'의 인덱스번호 = 0
    int end = uga.indexOf('b');
    // substring 하기
    sub_uga = uga.substring(start+1,end);
    }
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.drawString(0,1,sub_uga.c_str());
  u8x8.refreshDisplay();    // only required for SSD1606/7
  delay(500);
}
