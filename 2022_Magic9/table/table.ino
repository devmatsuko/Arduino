#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN1 3 //Arduino3ピンから出力(一番左)
#define PIN2 5 //Arduino5ピンから出力(左)
#define PIN3 9 //Arduino9ピンから出力(右)
#define PIN4 11 //Arduino11ピンから出力(一番右)
#define PIN5 6 //Arduino6ピンから出力(上)
#define NUM_LED 56 // 1本のLEDの数
#define NUM_LED2 112 // 四角のLEDの数
#define NUM_LED3 42 // DJ文字のLEDの数
#define BRIGHTNESS 100 //明るさ
#define Start 0 // 1本スタート
#define End 56 // 1本エンド
#define SQUARE_STAET 42 // 四角スタート
#define SQUARE_END 112 // 四角エンド
#define SQUARE_BOTTOM_START1 42 // 下辺スタート1
#define SQUARE_BOTTOM_END1 53 // 下辺エンド1
#define SQUARE_RIGHT_START 54 // 右辺スタート
#define SQUARE_RIGHT_END 63 // 右辺エンド
#define SQUARE_TOP_START 64 // 上辺スタート
#define SQUARE_TOP_END 88 // 上辺エンド
#define SQUARE_LEFT_START 89 // 左辺スタート
#define SQUARE_LEFT_END 98 // 左辺エンド
#define SQUARE_BOTTOM_START2 99 // 下辺スタート2
#define SQUARE_BOTTOM_END2 112 // 下辺エンド2

#define TestMode 0 // 動作確認用テストモード（On = 1、Off = 0)

Adafruit_NeoPixel strip[] = {
  Adafruit_NeoPixel(NUM_LED, PIN1, NEO_GRBW + NEO_KHZ800),
  Adafruit_NeoPixel(NUM_LED, PIN2, NEO_GRBW + NEO_KHZ800),
  Adafruit_NeoPixel(NUM_LED, PIN3, NEO_GRBW + NEO_KHZ800),
  Adafruit_NeoPixel(NUM_LED, PIN4, NEO_GRBW + NEO_KHZ800),
  Adafruit_NeoPixel(NUM_LED2, PIN5, NEO_GRBW + NEO_KHZ800)
};
 
//じわじわの輝度値
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
  215,218,220,223,225,228,231,233,236,239,241,244,247,249,252,255
};

// 色
const uint32_t white = strip[0].Color(0, 0, 0, 255);
const uint32_t red = strip[0].Color(255, 0, 0);
const uint32_t orange = strip[0].Color(255, 50, 0);
const uint32_t blue = strip[0].Color(0, 0, 255);
const uint32_t green = strip[0].Color(0, 255, 0);
const uint32_t yellow = strip[0].Color(100, 170, 0, 0);
const uint32_t black = strip[0].Color(0, 0, 0);

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code
  strip[0].setBrightness(BRIGHTNESS);
  strip[1].setBrightness(BRIGHTNESS);
  strip[2].setBrightness(BRIGHTNESS);
  strip[3].setBrightness(BRIGHTNESS);
  strip[4].setBrightness(BRIGHTNESS);
  strip[0].begin();
  strip[1].begin();
  strip[2].begin();
  strip[3].begin();
  strip[4].begin();
  strip[0].show();
  strip[1].show();
  strip[2].show();
  strip[3].show();
  strip[4].show();
}

void loop() {
  // テストモードがOnの場合
  if(TestMode == 1){
    fullColorAll(white,2000);
    fullColorAll(red,2000);
    fullColorAll(orange,2000);
    fullColorAll(green,2000);
    fullColorAll(blue,2000);
    fullColorAll(yellow,2000);
  } else {    
    //オープニング(16拍子目にスイッチオン」)
    part_1();
    // 1:08
    delay(30000);
    // 1:35(パート1の終わりの音でスイッチオン)
    delay(13000);
    // part2(2:07~3:37) 
    part_2();
    // ミニ4が消えたところでスイッチオン
    delay(11500);
    // 3:51
    part_3();
  }
   delay(10000000);//ループ防止
}

// 4本全部一色で表示する
void fullColorAll(uint32_t c, uint32_t wait) {
  for(uint16_t i=Start; i<=End; i++) {
    strip[0].setPixelColor(i, c);
    strip[1].setPixelColor(i, c);
    strip[2].setPixelColor(i, c);
    strip[3].setPixelColor(i, c);
  }
    strip[0].show();
    strip[1].show();
    strip[2].show();
    strip[3].show();
    delay(wait);
}

// 4本同時に任意の範囲一色で表示する
void colorWipeRangeAll(uint32_t c, uint32_t wait, uint32_t startLED1, uint32_t endLED1, uint32_t startLED2, uint32_t endLED2, uint32_t startLED3, uint32_t endLED3, uint32_t startLED4, uint32_t endLED4) {
  for(uint16_t i=startLED1; i<=endLED1; i++) {
    strip[0].setPixelColor(i, c);
  }
  for(uint16_t i=startLED2; i<=endLED2; i++) {
    strip[1].setPixelColor(i, c);
  }
  for(uint16_t i=startLED3; i<=endLED3; i++) {
    strip[2].setPixelColor(i, c);
  }
  for(uint16_t i=startLED4; i<=endLED4; i++) {
    strip[3].setPixelColor(i, c);
  }
    strip[0].show();
    strip[1].show();
    strip[2].show();
    strip[3].show();
    delay(wait);
}

// 1本の全範囲一色で表示する
void fullColorOne(uint8_t strip_number, uint32_t c, uint32_t wait) {
  for(uint16_t i=Start; i<=End; i++) {
    strip[strip_number].setPixelColor(i, c);
  }
  strip[strip_number].show();
  delay(wait);
}

// 1本の任意範囲一色で表示する
void colorWipeRangeOne(uint8_t strip_number, uint32_t c, uint32_t wait, uint32_t startLED, uint32_t endLED) {
  for(uint16_t i=startLED; i<=endLED; i++) {
    strip[strip_number].setPixelColor(i, c);
  }
    strip[strip_number].show();
    delay(wait);
}

// 四角全部一色で表示する
void fullColorSquareAll(uint32_t c, uint32_t wait) {
  for(uint16_t i=Start; i<=SQUARE_END; i++) {
    strip[4].setPixelColor(i, c);
  }
    strip[4].show();
    delay(wait);
}

// 四角1辺一色で表示する
void fullColorSquareOne(uint8_t side ,uint32_t c, uint32_t wait) {
  int start1;
  int end1;
  int start2;
  int end2;
  switch (side) {
    case 1:
      start1 = SQUARE_RIGHT_START;
      end1 = SQUARE_RIGHT_END;
    break;
    case 2:
      start1 = SQUARE_TOP_START;
      end1 = SQUARE_TOP_END;
    break;
    case 3:
      start1 = SQUARE_LEFT_START;
      end1 = SQUARE_LEFT_END;
    break;
    default:
      start1 = SQUARE_BOTTOM_START1;
      end1 = SQUARE_BOTTOM_END1;
      start2 = SQUARE_BOTTOM_START2;
      end2 = SQUARE_BOTTOM_END2;
    break;
  }
  for(uint16_t i=start1; i<=end1; i++) {
    strip[4].setPixelColor(i, c);
  }
  if (side == 0){
    for(uint16_t i=start2; i<=end2; i++) {
      strip[4].setPixelColor(i, c);
    }
  }
  strip[4].show();
  delay(wait);
}

// 基本リズム1 高さは全て同じ
void rhythm1(uint32_t c1, uint32_t c2, uint16_t time, uint8_t speed, uint8_t wait) {
  for(uint16_t i=0; i<=time; i++){
    // 下から上
    for(uint16_t j=strip[0].numPixels() - 1; j>=speed; j=j-speed) {
      for(uint8_t k=0; k<speed; k++){
        strip[0].setPixelColor(j-k, c1);
        strip[1].setPixelColor(j-k, c1);
        strip[2].setPixelColor(j-k, c1);
        strip[3].setPixelColor(j-k, c1);
      }
      strip[0].show();
      strip[1].show();
      strip[2].show();
      strip[3].show();
      delay(wait);
    }
    // 上から下。基本黒
    for(uint16_t l=1; l<strip[0].numPixels(); l=l+speed) {
      for(uint8_t m=0; m<speed; m++){
        strip[0].setPixelColor(l+m, c2);
        strip[1].setPixelColor(l+m, c2);
        strip[2].setPixelColor(l+m, c2);
        strip[3].setPixelColor(l+m, c2);
      }
      strip[0].show();
      strip[1].show();
      strip[2].show();
      strip[3].show();
      delay(wait);
    }
    delay(50);
  }
}

// じわじわ
void pulseWhite(uint16_t time,uint8_t wait,uint8_t speed,uint32_t c) {
   for(uint16_t k=0; k<=time-1; k++){ 
    for(int j = 0; j < 256 ; j = j+speed){
        for(uint16_t i=Start; i<End; i++) {
            strip[0].setPixelColor(i, strip[0].Color(0,0,0, neopix_gamma[j] ) );
        }
        for(uint16_t i=Start; i<End; i++) {
            strip[1].setPixelColor(i, strip[1].Color(0,0,0, neopix_gamma[j] ) );
        }
        for(uint16_t i=Start; i<End; i++) {
            strip[2].setPixelColor(i, strip[2].Color(0,0,0, neopix_gamma[j] ) );
        }
        for(uint16_t i=Start; i<End; i++) {
            strip[3].setPixelColor(i, strip[3].Color(0,0,0, neopix_gamma[j] ) );
        }
        for(uint16_t i=Start; i<SQUARE_END; i++) {
            strip[4].setPixelColor(i, strip[4].Color(0,0,0, neopix_gamma[j] ) );
        }
          delay(wait);
          strip[0].show();
          strip[1].show();
          strip[2].show();
          strip[3].show();
          strip[4].show();
        }
  
    for(int j = 255; j >= 0 ; j = j-speed){
       for(uint16_t i=Start; i<End; i++) {
            strip[0].setPixelColor(i, strip[0].Color(0,0,0, neopix_gamma[j] ) );
        }
        for(uint16_t i=Start; i<End; i++) {
            strip[1].setPixelColor(i, strip[1].Color(0,0,0, neopix_gamma[j] ) );
        }
        for(uint16_t i=Start; i<End; i++) {
            strip[2].setPixelColor(i, strip[2].Color(0,0,0, neopix_gamma[j] ) );
        }
        for(uint16_t i=Start; i<End; i++) {
            strip[3].setPixelColor(i, strip[3].Color(0,0,0, neopix_gamma[j] ) );
        }
        for(uint16_t i=Start; i<SQUARE_END; i++) {
            strip[4].setPixelColor(i, strip[4].Color(0,0,0, neopix_gamma[j] ) );
        }
          delay(wait);
          strip[0].show();
          strip[1].show();
          strip[2].show();
          strip[3].show();
          strip[4].show();
        }
        delay(100);
   }
}

// レインボー固定
void rainbow_moment(int wait) {
  for(int i=0; i<strip[0].numPixels(); i++) { 
    int pixelHue = (i * 65536L / strip[0].numPixels());
    strip[0].setPixelColor(i, strip[0].gamma32(strip[0].ColorHSV(pixelHue)));
  }
  for(int i=0; i<strip[1].numPixels(); i++) { 
    int pixelHue = (i * 65536L / strip[1].numPixels());
    strip[1].setPixelColor(i, strip[1].gamma32(strip[1].ColorHSV(pixelHue)));
  }
  for(int i=0; i<strip[2].numPixels(); i++) { 
    int pixelHue = (i * 65536L / strip[2].numPixels());
    strip[2].setPixelColor(i, strip[2].gamma32(strip[2].ColorHSV(pixelHue)));
  }
  for(int i=0; i<strip[3].numPixels(); i++) { 
    int pixelHue = (i * 65536L / strip[3].numPixels());
    strip[3].setPixelColor(i, strip[3].gamma32(strip[3].ColorHSV(pixelHue)));
  }
  for(int i=0; i<strip[4].numPixels(); i++) { 
    int pixelHue = (i * 65536L * 2 / strip[4].numPixels());
    strip[4].setPixelColor(i, strip[4].gamma32(strip[4].ColorHSV(pixelHue)));
  }
  strip[0].show();
  strip[1].show();
  strip[2].show();
  strip[3].show();
  strip[4].show();
  delay(wait);
}

// レインボー可変
void rainbow2(int wait) {
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    for(int i=0; i<strip[0].numPixels(); i++) { 
      int pixelHue = firstPixelHue + (i * 65536L / strip[0].numPixels());
      strip[0].setPixelColor(i, strip[0].gamma32(strip[0].ColorHSV(pixelHue)));
    }
    for(int i=0; i<strip[1].numPixels(); i++) { 
      int pixelHue = firstPixelHue + (i * 65536L / strip[1].numPixels());
      strip[1].setPixelColor(i, strip[1].gamma32(strip[1].ColorHSV(pixelHue)));
    }
    for(int i=0; i<strip[2].numPixels(); i++) { 
      int pixelHue = firstPixelHue + (i * 65536L / strip[2].numPixels());
      strip[2].setPixelColor(i, strip[2].gamma32(strip[2].ColorHSV(pixelHue)));
    }
    for(int i=0; i<strip[3].numPixels(); i++) { 
      int pixelHue = firstPixelHue + (i * 65536L / strip[3].numPixels());
      strip[3].setPixelColor(i, strip[3].gamma32(strip[3].ColorHSV(pixelHue)));
    }
    for(int i=0; i<strip[4].numPixels(); i++) { 
      int pixelHue = firstPixelHue + (i * 65536L / strip[4].numPixels());
      strip[4].setPixelColor(i, strip[4].gamma32(strip[4].ColorHSV(pixelHue)));
    }
    strip[0].show();
    strip[1].show();
    strip[2].show();
    strip[3].show();
    strip[4].show();
    delay(wait);
  }
  
}

// 動作確認用
void testSquare(uint32_t wait) {
  fullColorSquareAll(strip[0].Color(0, 0, 0, 255),2000);
  fullColorSquareAll(strip[0].Color(0, 155, 255,0),2000);
  fullColorSquareAll(strip[0].Color(255, 155, 0, 0),2000);
  fullColorSquareAll(strip[0].Color(0, 255, 155, 0),2000);
  fullColorSquareAll(strip[0].Color(0, 0, 0, 0),2000);
  fullColorSquareOne(0 ,strip[0].Color(0, 0, 0, 255), 2000);
  fullColorSquareOne(1 ,strip[0].Color(0, 155, 255,0), 2000);
  fullColorSquareOne(3 ,strip[0].Color(255, 155, 0, 0), 2000);
  fullColorSquareOne(2 ,strip[0].Color(0, 255, 155, 0), 2000);
  delay(wait);
}

void part_1() {
  delay(4300); //最初のリズムまで
  for(uint16_t i=0; i<4; i++) {
    fullColorOne(0, white,460);
    fullColorOne(0, black,0);
    fullColorOne(3, white,460);
    fullColorOne(3, black,0);
  }
  for(uint16_t i=0; i<4; i++) {
    fullColorOne(0, white,0);
    fullColorOne(1, white,460);
    fullColorOne(0, black, 0);
    fullColorOne(1, black, 0);
    fullColorOne(2, white,0);
    fullColorOne(3, white, 460);
    fullColorOne(2, black,0);
    fullColorOne(3, black ,0);
  }
  for(uint16_t i=0; i<4; i++) {
    fullColorOne(0, white,0);
    fullColorOne(2, white,460);
    fullColorOne(0, black,0);
    fullColorOne(2, black,0);
    fullColorOne(1, white,0);
    fullColorOne(3, white,460);
    fullColorOne(1, black,0);
    fullColorOne(3, black,0);
  }

  fullColorOne(0, white,460);
  fullColorOne(0, black,0);
  fullColorOne(1, white,460);
  fullColorOne(1, black,0);
  fullColorOne(2, white,460);
  fullColorOne(2, black,0);
  fullColorOne(3, white,460);
  fullColorOne(3, black,0);

  fullColorOne(0, white,460);
  fullColorOne(1, white,460);
  fullColorOne(2, white,460);
  fullColorOne(3, white,460);
  fullColorSquareAll(white,1000);

  // じわじわ消える
  for(int j = 255; j >= 0 ; j = j-3){
    for(uint16_t i=Start; i<End; i++) {
      strip[0].setPixelColor(i, strip[0].Color(0,0,0, neopix_gamma[j] ) );
      strip[1].setPixelColor(i, strip[1].Color(0,0,0, neopix_gamma[j] ) );
      strip[2].setPixelColor(i, strip[2].Color(0,0,0, neopix_gamma[j] ) );
      strip[3].setPixelColor(i, strip[3].Color(0,0,0, neopix_gamma[j] ) );
    }
    for(uint16_t i=Start; i<SQUARE_END; i++) {
      strip[4].setPixelColor(i, strip[1].Color(0,0,0, neopix_gamma[j] ) );
    }
    strip[0].show();
    strip[1].show();
    strip[2].show();
    strip[3].show();
    strip[4].show();
    delay(100);
  }
  delay(2000);
  // 一瞬ジワジワ
  pulseWhite(1,0,30,white);
  delay(1400);
  // リズム×16
  rhythm1(white, black, 16, 3, 2);
  delay(3000);
  // 下から上を白に
  // 4本
  for(uint16_t j=strip[0].numPixels() - 1; j>=2; j=j-2) {
    for(uint8_t k=0; k<2; k++){
      strip[0].setPixelColor(j-k, white);
      strip[1].setPixelColor(j-k, white);
      strip[2].setPixelColor(j-k, white);
      strip[3].setPixelColor(j-k, white);
    }
    strip[0].show();
    strip[1].show();
    strip[2].show();
    strip[3].show();
    delay(20);
  }
  // 四角下辺
  fullColorSquareOne(0, white, 20);
  // 四角両辺up
  for(uint16_t j=0; j<10; j=j+1) {

    strip[4].setPixelColor(SQUARE_RIGHT_START+j, white);
    strip[4].setPixelColor(SQUARE_LEFT_END-j, white);
    
    strip[4].show();
    delay(20);
  }
  // 四角上辺
  fullColorSquareOne(2, white, 20);

  // 下から上を黒に
  // 4本
  for(uint16_t x=strip[0].numPixels() - 1; x>=1; x=x-1) {
    strip[0].setPixelColor(x, black);
    strip[1].setPixelColor(x, black);
    strip[2].setPixelColor(x, black);
    strip[3].setPixelColor(x, black);

    strip[0].show();
    strip[1].show();
    strip[2].show();
    strip[3].show();
    delay(20);
  }
  // 四角下辺
  fullColorSquareOne(0, strip[4].Color(0, 0, 0), 20);
  // 四角両辺up
  for(uint16_t y=0; y<10; y=y+1) {
    
    strip[4].setPixelColor(SQUARE_RIGHT_START+y, strip[4].Color(0, 0, 0));
    strip[4].setPixelColor(SQUARE_LEFT_END-y, strip[4].Color(0, 0, 0));
    
    strip[4].show();
    delay(20);
  }
  // 四角上辺
  for(uint16_t z=0; z<12; z=z+1) {
    strip[4].setPixelColor(SQUARE_TOP_START+z, strip[4].Color(0, 0, 0));
    strip[4].setPixelColor(SQUARE_TOP_END-z, strip[4].Color(0, 0, 0));
    
    strip[4].show();
    delay(20);
  }
  fullColorSquareOne(2, black, 0);
  // 0:59
  delay(8700);
  // 1:08
}

void part_2() {
  // 全部消える  
  fullColorSquareAll(black,0);
  fullColorAll(black,0);
  delay(500);
  for(uint16_t i=0; i<24; i++) {
    fullColorOne(0, green,0);
    fullColorOne(2, green,455);
    fullColorOne(0, black,0);
    fullColorOne(2, black,0);
    fullColorOne(1, green,0);
    fullColorOne(3, green,455);
    fullColorOne(1, black,0);
    fullColorOne(3, black,0);
  }
  fullColorOne(0, green,455);
  fullColorOne(1, green,455);
  fullColorOne(2, green,455);
  fullColorOne(3, green,455);
  fullColorOne(0, black,455);
  fullColorOne(1, black,455);
  fullColorOne(2, black,455);
  fullColorOne(3, black,0);
  // 2:18
  delay(51100);
  // 3:09
  // 左から赤になる
  fullColorOne(0, red,460);
  fullColorOne(1, red,460);
  fullColorOne(2, red,460);
  fullColorOne(3, red,460);
  fullColorSquareAll(red,0);
  // 3:11
  delay(2900);
  // 3:12
  // 左から青になる
  fullColorOne(0, blue,50);
  fullColorOne(1, blue,50);
  fullColorOne(2, blue,50);
  fullColorOne(3, blue,650);
  fullColorSquareAll(blue,0);
  delay(5700);
  // 3:20
  // 全色黄色 
  fullColorAll(yellow,0);
  fullColorSquareAll(yellow,0);
  delay(1500);
  // 3:22
  // 全色レインボー
  rainbow_moment(4000);
  // 3:26
  // 全部消える  
  fullColorSquareAll(black,0);
  fullColorAll(black,0);
}

void part_3() {
  // 3:36:~3:44ジワジワ
  pulseWhite(10,0,15,white);
  delay(23000);
  // 4:07
  // 全色レインボー
  rainbow_moment(0);
  delay(5000);
  // 4:12
  // 全部消える
  fullColorOne(0, black,0);
  fullColorOne(3, black,350);
  fullColorOne(1, black,0);
  fullColorOne(2, black,350);
  fullColorSquareAll(black,0);
  // 4:13
  delay(38500);
  // 4:52
  rainbow_moment(0);
  delay(18500);
  // 5:09
  // 下から上を黒に
  // 4本
  for(uint16_t x=strip[0].numPixels() - 1; x>=1; x=x-1) {
    strip[0].setPixelColor(x, black);
    strip[1].setPixelColor(x, black);
    strip[2].setPixelColor(x, black);
    strip[3].setPixelColor(x, black);

    strip[0].show();
    strip[1].show();
    strip[2].show();
    strip[3].show();
    delay(50);
  }
  // 四角下辺
  fullColorSquareOne(0, strip[4].Color(0, 0, 0), 50);
  // 四角両辺up
  for(uint16_t y=0; y<10; y=y+1) {
    
    strip[4].setPixelColor(SQUARE_RIGHT_START+y, strip[4].Color(0, 0, 0));
    strip[4].setPixelColor(SQUARE_LEFT_END-y, strip[4].Color(0, 0, 0));
    
    strip[4].show();
    delay(50);
  }
  // 四角上辺
  fullColorSquareOne(2, strip[4].Color(0, 0, 0), 50);

  // 5:14
  delay(5500);
  // 5:20
  // 一瞬ジワジワ
  pulseWhite(1,0,30,white);
}

