#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN1 6 //Arduino6ピンから出力
#define PIN2 7 //Arduino7ピンから出力
#define NUM_LEDS1 214
#define NUM_LEDS2 106
#define BRIGHTNESS 50 //明るさ
#define RightStart 0 //右スタート
#define RightEnd 108 //右エンド
#define LeftStart 109 //左スタート
#define LeftEnd 214 //左エンド

//0～39が右外
#define RightOutStart 0
#define RightOutEnd 33

//40～77が右腕
#define RightArmStart 34
#define RightArmAheadEnd 55 //肩から先
#define RightArmAheadStart 56
#define RightArmEnd 70

//77～123が右内
#define RightInStart 71
#define RightInEnd 108

//124～168が左内
#define LeftInStart 109
#define LeftInEnd 146

//169～206が左腕
#define LeftArmStart 147
#define LeftArmAheadEnd 161
#define LeftArmAheadStart 162
#define LeftArmEnd 179

//207～275が左外
#define LeftOutStart 180
#define LeftOutEnd 214

//0～28が左足外
#define LeftOutFootStart 0
#define LeftOutFootEnd 28

//29～52が左足内
#define LeftInFootStart 29
#define LeftInFootEnd 52

//53～76が右足内
#define RightInFootStart 53
#define RightInFootEnd 76

//77～105が右足外
#define RightOutFootStart 77
#define RightOutFootEnd 105

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(NUM_LEDS1, PIN1, NEO_GRBW + NEO_KHZ800); //テープ1の定義
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUM_LEDS2, PIN2, NEO_GRBW + NEO_KHZ800); //テープ2の定義
uint16_t top=0;


//じわじわの値
  byte neopix_gamma[] = {
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
    2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
    5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
   10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
   17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
   25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
   37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
   51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
   69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
   90, 92, 93, 95, 96, 98, 99,101,102,104,105,107,109,110,112,114,
  115,117,119,120,122,124,126,127,129,131,133,135,137,138,140,142,
  144,146,148,150,152,154,156,158,160,162,164,167,169,171,173,175,
  177,180,182,184,186,189,191,193,196,198,200,203,205,208,210,213,
  215,218,220,223,225,228,231,233,236,239,241,244,247,249,252,255 };

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code
  strip1.setBrightness(BRIGHTNESS);
  strip2.setBrightness(BRIGHTNESS);
  strip1.begin();
  strip2.begin();
  strip1.show(); // Initialize all pixels to 'off' 
  strip2.show(); // Initialize all pixels to 'off' 
}

void loop() {
  // Some example procedures showing how to display to the pixels:

//イントロスタート
  
  delay(4000);  //プーンから最初の点滅まで
  random1(strip1.Color(255, 255, 255), 25, 500); //0:15～0:22
  //pulseWhite(uint16_t time,uint8_t wait,uint32_t c, uint32_t startLed1, uint32_t endLed1,uint32_t startLed2, uint32_t endLed2) {
  pulseWhite(1,0,6,strip1.Color(255, 255, 255), RightInStart, RightInEnd, LeftInStart, LeftInEnd, LeftInStart, LeftInEnd, LeftInFootStart, RightInFootEnd);
  pulseWhite(1,0,6,strip1.Color(255, 255, 255), RightOutStart, RightOutEnd, RightInStart, LeftInEnd, LeftOutStart, LeftOutEnd, LeftOutFootStart, RightOutFootEnd);
  pulseWhite(1,0,5,strip1.Color(255, 255, 255), RightOutStart, LeftOutEnd, RightOutStart, LeftOutEnd, RightOutStart, LeftOutEnd, LeftOutFootStart, RightOutFootEnd);
  delay(9000);
  colorWipeRange(strip1.Color(0, 155, 255), 0, RightInStart, RightInEnd, RightInFootStart, RightInFootEnd);
  colorWipeRange(strip1.Color(0, 155, 255), 0, LeftInStart, LeftInEnd, LeftInFootStart, LeftInFootEnd);
  delay(100);
  colorWipeRange(strip1.Color(0, 155, 255), 0, RightOutStart, RightOutEnd, RightOutFootStart, RightOutFootEnd);
  colorWipeRange(strip1.Color(0, 155, 255), 0, LeftOutStart, LeftOutEnd, LeftOutFootStart, LeftOutFootEnd);
  delay(100);
  colorWipeRange(strip1.Color(0, 155, 255), 0, RightArmStart, RightArmEnd, RightOutFootStart, RightOutFootEnd);
  colorWipeRange(strip1.Color(0, 155, 255), 0, LeftArmStart, LeftArmEnd, RightOutFootStart, RightOutFootEnd);
  delay(100);
  delay(2000);
  colorWipeRange(strip1.Color(0, 0, 0), 0, RightStart, LeftEnd, LeftOutFootStart, RightOutFootEnd ); // 消す
  delay(3000);
  armColorMoveUpToDown5(strip1.Color(255, 255, 255), 5, 1, 1);
  //ここまでで0:43
  delay(21000);
  //1:04までスリープ
  armColorMoveDownToUp5(strip1.Color(255, 255, 255), 5, 1, 0);
  colorWipeRange(strip1.Color(255, 255, 255), 0, RightOutEnd-10, RightOutEnd,1000,1000);
  delay(80); 
  colorWipeRange(strip1.Color(0, 0, 0), 0, RightOutEnd-10, RightOutEnd,1000,1000); 
  colorWipeRange(strip1.Color(255, 255, 255), 0, RightInStart, RightInStart+10,1000,1000); 
  delay(80);  
  colorWipeRange(strip1.Color(0, 0, 0), 0, RightInStart, RightInStart+10,1000,1000); 
  colorWipeRange(strip1.Color(255, 255, 255), 0, LeftInEnd-10,  LeftInEnd,1000,1000);
  delay(80);
  colorWipeRange(strip1.Color(0, 0, 0), 0, LeftInEnd-10,  LeftInEnd,1000,1000);
  colorWipeRange(strip1.Color(255, 255, 255), 0, LeftOutStart, LeftOutStart+10,1000,1000); 
  delay(80);
  colorWipeRange(strip1.Color(0, 0, 0), 0, LeftOutStart, LeftOutStart+10,1000,1000); 
  armColorMoveUpToDown5(strip1.Color(255, 255, 255), 5, 0, 1);
  //ここまでで1:07
  delay(7500);
  //1:14までスリープ
  // 流れながら点滅
  theaterChase(strip1.Color(255, 255, 255), 20,70); // White
  colorWipeRange(strip1.Color(0, 0, 0), 0, RightStart, LeftEnd, LeftOutFootStart, RightOutFootEnd); // 消す
  delay(7300);
  //ここまで1:29
  //全部白
  colorWipeRange(strip1.Color(255, 255, 255), 0, RightStart, LeftEnd, LeftOutFootStart, RightOutFootEnd); 
  delay(2000);
  colorWipeRange(strip1.Color(0, 0, 0), 0, RightStart, LeftEnd, LeftOutFootStart, RightOutFootEnd); // 消す
  //ここまで1:31
  delay(94200);
  
  //ここまで3:06
  pulseWhite(1,0,20,strip1.Color(0, 155, 255), RightInStart, RightInEnd, LeftInStart, LeftInEnd, LeftInStart, LeftInEnd,LeftInFootStart, RightInFootEnd);
  pulseWhite(1,0,20,strip1.Color(0, 155, 255), RightOutStart, RightOutEnd, RightInStart, LeftInEnd, LeftOutStart, LeftOutEnd, LeftOutFootStart, RightOutFootEnd);
  pulseWhite(1,0,20,strip1.Color(0, 155, 255), RightOutStart, LeftOutEnd, RightOutStart, LeftOutEnd, RightOutStart, LeftOutEnd, LeftOutFootStart, RightOutFootEnd);
  //ここまで3:09
  delay(13500);
  armColorMoveUpToDown5(strip1.Color(0, 155, 255), 8, 1, 0);
  armColorMoveUpToDown5(strip1.Color(0, 155, 255), 8, 1, 0);
  //ここまで3:24
  delay(900);
  colorWipeRange(strip1.Color(0, 155, 255), 0, RightStart, LeftEnd, LeftOutFootStart, RightOutFootEnd); 
  delay(7100);
  colorWipeRange(strip1.Color(0, 255, 50), 0, RightStart, LeftEnd, LeftOutFootStart, RightOutFootEnd); 
  //ここまで3:34
  delay(4000);
  colorWipeRange(strip1.Color(255, 255, 0), 0, RightStart, LeftEnd, LeftOutFootStart, RightOutFootEnd); 
  delay(3000);
  colorWipeRange(strip1.Color(0, 0, 0), 0, RightArmStart, RightArmEnd, LeftOutFootStart, RightOutFootEnd);
  colorWipeRange(strip1.Color(0, 0, 0), 0, LeftArmStart, LeftArmEnd, LeftOutFootStart, RightOutFootEnd);
  colorWipeRange(strip1.Color(0, 255, 50), 0, RightOutStart, RightOutEnd, RightOutFootStart, RightOutFootEnd);
  colorWipeRange(strip1.Color(0, 155, 255), 0, RightInStart, RightInEnd, RightInFootStart, RightInFootEnd);
  colorWipeRange(strip1.Color(255, 0, 55), 0, LeftInStart, LeftInEnd, LeftInFootStart, LeftInFootEnd);
  colorWipeRange(strip1.Color(255, 255, 0), 0, LeftOutStart, LeftOutEnd, LeftOutFootStart, LeftOutFootEnd);
  delay(2000);
  colorWipeRange(strip1.Color(0, 0, 0), 0, RightOutStart, RightOutEnd, RightOutFootStart, RightOutFootEnd);
  delay(500);
  colorWipeRange(strip1.Color(0, 0, 0), 0, RightInStart, RightInEnd, RightInFootStart, RightInFootEnd);
  delay(500);
  colorWipeRange(strip1.Color(0, 0, 0), 0, LeftInStart, LeftInEnd, LeftInFootStart, LeftInFootEnd);
  delay(500);
  colorWipeRange(strip1.Color(255, 255, 0), 0, RightStart, LeftEnd, LeftOutFootStart, RightOutFootEnd); 
  //ここまで3:44
  delay(4000); 
  colorWipeRange(strip1.Color(0, 0, 0), 0, RightStart, LeftEnd, LeftOutFootStart, RightOutFootEnd); 
  delay(3000);
  footColorMoveUpToDown5(strip1.Color(255, 255, 0), 8, 0, 1);
  //ここまで3:52
  delay(65600);

  //ここまで4:56
  colorWipeRange(strip1.Color(0, 155, 255), 0, RightStart, LeftEnd, LeftOutFootStart, RightOutFootEnd); // 全身青
  delay(500);
  colorWipeRange(strip1.Color(0, 0, 0), 0, RightStart, LeftEnd, LeftOutFootStart, RightOutFootEnd); // 消す
  theaterChase(strip1.Color(0, 155, 255),20,30); // White
  colorWipeRange(strip1.Color(0, 0, 0), 0, RightStart, LeftEnd, LeftOutFootStart, RightOutFootEnd); // 消す
  inToOut(strip1.Color(0, 155, 255),100,4);
  colorWipeRange(strip1.Color(0, 155, 255), 0, RightStart, LeftEnd, LeftOutFootStart, RightOutFootEnd);
  delay(1500);
  colorWipeRange(strip1.Color(0, 0, 0), 0, RightStart, LeftEnd, LeftOutFootStart, RightOutFootEnd); // 消す
  delay(6000);
  //ここまで5:11
  colorWipeRange(strip1.Color(255, 255, 255), 0, RightStart, LeftEnd, LeftOutFootStart, RightOutFootEnd); // 全身白
  delay(2000);
  colorWipeRange(strip1.Color(0, 0, 0), 0, RightStart, LeftEnd, LeftOutFootStart, RightOutFootEnd);
  colorWipeRange(strip1.Color(255, 255, 255), 0, RightArmStart, RightArmEnd, 1000, 1000); // 右腕白
  colorWipeRange(strip1.Color(255, 255, 255), 0, LeftArmStart, LeftArmEnd, 1000, 1000); // 左腕白
  delay(3000);
  //ここまで5:16 
  colorWipeRange(strip1.Color(0, 0, 0), 0, RightStart, LeftEnd, LeftOutFootStart, RightOutFootEnd); // 消す
  colorWipeRange(strip1.Color(0, 155, 255), 0, RightArmStart, RightArmEnd, 1000, 1000); // 右腕青
  colorWipeRange(strip1.Color(0, 155, 255), 0, LeftArmStart, LeftArmEnd, 1000, 1000); // 左腕青
  delay(10000);
  //armColorWipeRhythm(strip1.Color(0, 155, 255),0.5,22,1,1);
  //ここまで5:26
  colorWipeRange(strip1.Color(0, 155, 255), 0, RightStart, LeftEnd, LeftOutFootStart, RightOutFootEnd); // 全身ピンク
  delay(9000);
  colorWipeRange(strip1.Color(0, 0, 0), 0, RightStart, LeftEnd, LeftOutFootStart, RightOutFootEnd); // 消す
  //ここまで5:35
  delay(43700);
  //ここまで6:19
  delay(1800);
  colorWipeRange(strip1.Color(0, 155, 255), 0, RightStart, LeftEnd, LeftOutFootStart, RightOutFootEnd); // 全身ピンク
  delay(1800);
  delay(3000);
  rainbow(0);
  //delay(1000);
  //colorWipeRange(strip1.Color(0, 0, 0), 0, RightStart, LeftEnd, LeftOutFootStart, RightOutFootEnd); // 消す

  
  
   delay(10000000);//ループ防止
}

// こっからメソッド
//全部白

//任意に範囲カラー
void colorWipeRange(uint32_t c, uint32_t wait, uint32_t startLED1, uint32_t endLED1, uint32_t startLED2, uint32_t endLED2) {
  for(uint16_t i=startLED1; i<=endLED1; i++) {
    strip1.setPixelColor(i, c);
  }
  for(uint16_t i=startLED2; i<=endLED2; i++) {
    strip2.setPixelColor(i, c);
  }
    strip1.show();
    strip2.show();
    delay(wait);
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256 * 5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip1.numPixels(); i++) {
      strip1.setPixelColor(i, Wheel(((i * 256 / strip1.numPixels()) + j) & 255));
      strip2.setPixelColor(i, Wheel(((i * 256 / strip2.numPixels()) + j) & 255));
    }
    strip1.show();
    strip2.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;
  for(j=0; j<256; j++) {
    for(i=0; i<strip1.numPixels(); i++) {
      strip1.setPixelColor(i, Wheel((i+j) & 255));
      strip2.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip1.show();
    strip2.show();
    delay(wait);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip1.Color(255 - WheelPos * 3, 0, WheelPos * 3,0);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip1.Color(0, WheelPos * 3, 255 - WheelPos * 3,0);
  }
  WheelPos -= 170;
  return strip1.Color(WheelPos * 3, 255 - WheelPos * 3, 0,0);
}

//１～Nの順に光るメソッド
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip1.numPixels(); i++) {
    strip1.setPixelColor(i, c);
    strip1.show();
    delay(wait);
  }
}

//両腕腕5個ずつ移動する(肩⇒腕)
void armColorMoveUpToDown5(uint32_t c, uint8_t wait, uint8_t rightFlag, uint8_t leftFlag) {
  for(uint16_t k=0; k<35; k++) {
    if(rightFlag == 1){
      if(RightArmStart+k <= RightArmAheadEnd){
        strip1.setPixelColor(RightArmStart+k, c);
      }
      if(RightArmEnd-k >= RightArmAheadStart){
        strip1.setPixelColor(RightArmEnd-k, c);
      }
    }
    if(leftFlag == 1){
      if(LeftArmStart+k <= LeftArmAheadEnd){
        strip1.setPixelColor(LeftArmStart+k, c);
      }
      if(LeftArmEnd-k >= LeftArmAheadStart){
        strip1.setPixelColor(LeftArmEnd-k, c); 
      }
    }
    strip1.show();
    delay(wait);
    strip1.setPixelColor(RightArmStart+k-5, strip1.Color(0,0,0));
    strip1.setPixelColor(RightArmEnd-k+5, strip1.Color(0,0,0));
    strip1.setPixelColor(LeftArmStart+k-5, strip1.Color(0,0,0));
    strip1.setPixelColor(LeftArmEnd-k+5, strip1.Color(0,0,0)); 
    strip1.show();
    delay(wait);
  }
}

//両腕腕5個ずつ移動する(腕⇒肩)
void armColorMoveDownToUp5(uint32_t c, uint8_t wait, uint8_t rightFlag, uint8_t leftFlag) {
  for(uint16_t k=0; k<35; k++) {
    if(rightFlag == 1){
      if(RightArmAheadEnd-k >= RightArmStart){
        strip1.setPixelColor(RightArmAheadEnd-k, c);
      }
      if(RightArmAheadStart+k <= RightArmEnd){
        strip1.setPixelColor(RightArmAheadStart+k, c);
      }
    }
    if(leftFlag == 1){
      if(LeftArmAheadEnd-k >= LeftArmStart){
        strip1.setPixelColor(LeftArmAheadEnd-k, c);
      }
      if(LeftArmAheadStart+k <= LeftArmEnd){
        strip1.setPixelColor(LeftArmAheadStart+k, c); 
      }
    }
    strip1.show();
    delay(wait);
    if(k >= 5){
      strip1.setPixelColor(RightArmAheadEnd-k+5, strip1.Color(0,0,0));
      strip1.setPixelColor(RightArmAheadStart+k-5, strip1.Color(0,0,0));
      strip1.setPixelColor(LeftArmAheadEnd-k+5, strip1.Color(0,0,0));
      strip1.setPixelColor(LeftArmAheadStart+k-5, strip1.Color(0,0,0)); 
      strip1.show();
    }
    delay(wait);
  }
}

//両腕肩⇒腕⇒肩に向かって順に光っていく
void armColorWipeRhythm(uint32_t c, uint8_t wait, uint8_t time, uint8_t rightFlag, uint8_t leftFlag) {
  for(uint16_t i=0; i<time; i++) {
    for(uint16_t k=0; k<27; k++) {
      if(rightFlag == 1){
        if(RightArmStart+k <= RightArmAheadEnd){
          strip1.setPixelColor(RightArmStart+k, c);
        }
        if(RightArmEnd-k >= RightArmAheadStart){
          strip1.setPixelColor(RightArmEnd-k, c);
        }
      }
      if(leftFlag == 1){
        if(LeftArmStart+k <= LeftArmAheadEnd){
          strip1.setPixelColor(LeftArmStart+k, c);
        }
        if(LeftArmEnd-k >= LeftArmAheadStart){
          strip1.setPixelColor(LeftArmEnd-k, c); 
        }
      }
      strip1.show();
      delay(wait);
    }
    for(uint16_t k=0; k<27; k++) {
      if(rightFlag == 1){
        if(RightArmAheadEnd-k >= RightArmStart){
          strip1.setPixelColor(RightArmAheadEnd-k, strip1.Color(0,0,0));
        }
        if(RightArmAheadStart+k <= RightArmEnd){
          strip1.setPixelColor(RightArmAheadStart+k, strip1.Color(0,0,0));
        }
      }
      if(leftFlag == 1){
        if(LeftArmAheadEnd-k >= LeftArmStart){
          strip1.setPixelColor(LeftArmAheadEnd-k, strip1.Color(0,0,0));
        }
        if(LeftArmAheadStart+k <= LeftArmEnd){
          strip1.setPixelColor(LeftArmAheadStart+k, strip1.Color(0,0,0)); 
        }
      }
      strip1.show();
      delay(wait);
    }
  }
}


//両足5個ずつ移動する(上⇒下)
void footColorMoveUpToDown5(uint32_t c, uint8_t wait, uint8_t rightFlag, uint8_t leftFlag) {
  for(uint16_t k=0; k<35; k++) {
    if(rightFlag == 1){
      if(RightInFootStart+k <= RightInFootEnd){
        strip2.setPixelColor(RightInFootStart+k, c);
      }
      if(RightOutFootEnd-k >= RightOutFootStart){
        strip2.setPixelColor(RightOutFootEnd-k, c);
      }
    }
    if(leftFlag == 1){
      if(LeftOutFootStart+k <= LeftOutFootEnd){
        strip2.setPixelColor(LeftOutFootStart+k, c);
      }
      if(LeftInFootEnd-k >= LeftInFootStart){
        strip2.setPixelColor(LeftInFootEnd-k, c); 
      }
    }
    strip2.show();
    delay(wait);
    strip2.setPixelColor(RightInFootStart+k-5, strip2.Color(0,0,0));
    strip2.setPixelColor(RightOutFootEnd-k+5, strip2.Color(0,0,0));
    strip2.setPixelColor(LeftOutFootStart+k-5, strip2.Color(0,0,0));
    strip2.setPixelColor(LeftInFootEnd-k+5, strip2.Color(0,0,0)); 
    strip2.show();
    delay(wait);
  }
}

//左右赤点滅
void alternate(uint32_t c, uint32_t cycle){
  for(uint16_t i=0; i<cycle; i++) {
    colorWipeRange(c, 0, RightStart, RightEnd, RightInFootStart, RightOutFootEnd);
    delay(20);
    colorWipeRange(strip1.Color(0, 0, 0), 0, RightStart, RightEnd, RightInFootStart, RightOutFootEnd);
    delay(100);
    colorWipeRange(c, 0, LeftStart, LeftEnd, LeftOutFootStart, LeftInFootEnd);
    delay(20);
    colorWipeRange(strip1.Color(0, 0, 0), 0, LeftStart, LeftEnd,LeftOutFootStart, LeftInFootEnd);
    delay(100);
  }
}

//基本リズム1
void rhythm1(uint32_t c1, uint32_t c2, uint16_t time, uint8_t wait) {
  for(uint16_t i=0; i<=time; i++){
    for(uint16_t j=strip1.numPixels() - 1; j>=2; j=j-2) {
      strip1.setPixelColor(j, c1);
      strip1.setPixelColor(j-1, c1);
      strip1.show();
      delay(wait);
    }
    for(uint16_t k=0; k<strip1.numPixels(); k=k+2) {
      strip1.setPixelColor(k, c2);
      strip1.setPixelColor(k+1, c2);
      strip1.show();
      delay(wait);
    }
    //delay(1);
  }
}


//ランダムに10か所転々と光る
void random1(uint32_t c, uint16_t time, uint8_t wait) {
  uint32_t ledPosition1;
  uint32_t ledPosition2;
  for(uint16_t i=0; i<=time; i++){
    ledPosition1 = random(RightOutStart, LeftEnd);
    ledPosition2 = random(LeftOutFootStart, RightOutFootEnd);
    for(uint16_t i=ledPosition1; i<ledPosition1 + 10; i++) {
      strip1.setPixelColor(i, c);
    }
    for(uint16_t i=ledPosition2; i<ledPosition2 + 10; i++) {
      strip2.setPixelColor(i, c);
    }
    strip1.show();
    strip2.show();
    delay(wait);
    for(uint16_t i=ledPosition1; i<ledPosition1 + 10; i++) {
      strip1.setPixelColor(i, strip1.Color(0, 0, 0));
    }
    for(uint16_t i=ledPosition2; i<ledPosition2 + 10; i++) {
      strip2.setPixelColor(i, strip2.Color(0, 0, 0));
    }
    strip1.show();
    strip2.show();
  }
}



//じわじわホワイト(はやめ)
void pulseWhite(uint16_t time,uint8_t wait,uint8_t speed,uint32_t c, uint32_t startLed1, uint32_t endLed1,uint32_t startLed2, uint32_t endLed2,uint32_t startLed3, uint32_t endLed3,uint32_t startLed4, uint32_t endLed4) {
   for(uint16_t k=0; k<=time-1; k++){ 
    for(int j = 0; j < 256 ; j = j+speed){
        for(uint16_t i=startLed1; i<endLed1; i++) {
            strip1.setPixelColor(i, strip1.Color(0,0,0, neopix_gamma[j] ) );
        }
        for(uint16_t i=startLed2; i<endLed2; i++) {
            strip1.setPixelColor(i, strip1.Color(0,0,0, neopix_gamma[j] ) );
        }
        for(uint16_t i=startLed3; i<endLed3; i++) {
            strip1.setPixelColor(i, strip1.Color(0,0,0, neopix_gamma[j] ) );
        }
        for(uint16_t i=startLed4; i<endLed4; i++) {
            strip2.setPixelColor(i, strip2.Color(0,0,0, neopix_gamma[j] ) );
        }
          delay(wait);
          strip1.show();
          strip2.show();
        }
  
    for(int j = 255; j >= 0 ; j = j-4){
       for(uint16_t i=startLed1; i<endLed1; i++) {
            strip1.setPixelColor(i, strip1.Color(0,0,0, neopix_gamma[j] ) );
        }
        for(uint16_t i=startLed2; i<endLed2; i++) {
            strip1.setPixelColor(i, strip1.Color(0,0,0, neopix_gamma[j] ) );
        }
        for(uint16_t i=startLed3; i<endLed3; i++) {
            strip1.setPixelColor(i, strip1.Color(0,0,0, neopix_gamma[j] ) );
        }
        for(uint16_t i=startLed4; i<endLed4; i++) {
            strip2.setPixelColor(i, strip2.Color(0,0,0, neopix_gamma[j] ) );
        }
          delay(wait);
          strip1.show();
          strip2.show();
        }
        delay(100);
   }
}



// 流れながら点滅(単色)
void theaterChase(uint32_t c, uint8_t wait,uint8_t cycle ) {
  for (int j=0; j<cycle; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip1.numPixels(); i=i+3) {
        strip1.setPixelColor(i+q, c);    //turn every third pixel on
        strip2.setPixelColor(i+q, c);
      }
      strip1.show();
      strip2.show();

      delay(wait);

      for (uint16_t i=0; i < strip1.numPixels(); i=i+3) {
        strip1.setPixelColor(i+q, 0);        //turn every third pixel off
        strip2.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}


// 流れながら点滅レインボー
void theaterChaseRainbow(uint8_t wait, uint8_t cycle) {
  for (int j=0; j < cycle; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip1.numPixels(); i=i+3) {
        strip1.setPixelColor(i+q, Wheel( (i+j) % 255));
        strip2.setPixelColor(i+q, Wheel( (i+j) % 255));//turn every third pixel on
      }
      strip1.show();
      strip2.show();

      delay(wait);

      for (uint16_t i=0; i < strip1.numPixels(); i=i+3) {
        strip1.setPixelColor(i+q, 0);
        strip2.setPixelColor(i+q, 0);//turn every third pixel off
      }
    }
  }
}

// 内から外に光っていくメソッド
void inToOut(uint32_t c,uint8_t wait, uint8_t cycle) {
  for (int j=0; j < cycle; j++) {
    delay(wait);
    colorWipeRange(c, 0, RightInStart, RightInEnd, RightInFootStart, RightInFootEnd);
    colorWipeRange(c, 0, LeftInStart, LeftInEnd, LeftInFootStart, LeftInFootEnd);
    delay(wait);
    colorWipeRange(c, 0, RightOutStart, RightOutEnd, RightOutFootStart, RightOutFootEnd);
    colorWipeRange(c, 0, LeftOutStart, LeftOutEnd, LeftOutFootStart, LeftOutFootEnd);
    delay(wait);
    colorWipeRange(c, 0, RightArmStart, RightArmEnd,1000,1000);
    colorWipeRange(c, 0, LeftArmStart, LeftArmEnd,1000,1000);
    delay(wait);
    colorWipeRange(strip1.Color(0, 0, 0), 0, RightStart, LeftEnd,LeftOutFootStart, RightOutFootEnd);
  }
}




uint8_t red(uint32_t c) {
  return (c >> 16);
}
uint8_t green(uint32_t c) {
  return (c >> 8);
}
uint8_t blue(uint32_t c) {
  return (c);
}
