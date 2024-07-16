#include <Wire.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 oled(128, 32, &Wire, -1);

uint32_t pre_time;
int32_t count= 0;


void setup(){
oled.begin(SSD1306_SWITCHCAPVCC,0x3C);
delay(2000);
oled.clearDisplay();
oled.setTextColor(WHITE);
pre_time= millis();
}
void loop(){
  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setCursor(30,0);
  oled.println("Count");
  if(millis()- pre_time >= 1000){
    count--;
    pre_time = millis();
    if(count<0){
      count = 10;
    }
  }
oled.setTextSize(2);
oled.setCursor(50,15);
oled.println(count);
oled.display();
}
