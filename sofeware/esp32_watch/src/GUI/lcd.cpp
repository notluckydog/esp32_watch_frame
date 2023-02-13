
#include "lcd.h"
#include "key.h"
#include "pic_ico.h"
#include <Arduino.h>

TFT_eSPI tft = TFT_eSPI();  
TFT_eSprite screen = TFT_eSprite(&tft);



void showImage(int32_t x, int32_t y, int32_t w, int32_t h, const uint16_t *data);//函数声明
 
#define PI_BUF_SIZE 128
void showImage(int32_t x, int32_t y, int32_t w, int32_t h, const uint16_t *data){
  int32_t dx = 0;
  int32_t dy = 0;
  int32_t dw = w;
  int32_t dh = h*2;
 
  if (x < 0) { dw += x; dx = -x; x = 0; }
  if (y < 0) { dh += y; dy = -y; y = 0; }
 
  if (dw < 1 || dh < 1) return;
 
  CS_L;
 
  data += dx + dy * w;
 
  uint16_t  buffer[PI_BUF_SIZE];
  uint16_t* pix_buffer = buffer;
  uint16_t  high,low;
 
  tft.setWindow(x, y, x + dw - 1, y + dh - 1);
 
  // Work out the number whole buffers to send
  uint16_t nb = (dw * dh) / (2 * PI_BUF_SIZE);
 
  // Fill and send "nb" buffers to TFT
  for (int32_t i = 0; i < nb; i++) {
    for (int32_t j = 0; j < PI_BUF_SIZE; j++) {
      high = pgm_read_word(&data[(i * 2 * PI_BUF_SIZE) + 2 * j + 1]);
      low = pgm_read_word(&data[(i * 2 * PI_BUF_SIZE) + 2 * j ]);
      pix_buffer[j] = (high<<8)+low;
    }
    tft.pushPixels(pix_buffer, PI_BUF_SIZE);
  }
 
  // Work out number of pixels not yet sent
  uint16_t np = (dw * dh) % (2 * PI_BUF_SIZE);
 
  // Send any partial buffer left over
  if (np) {
    for (int32_t i = 0; i < np; i++)
    {
      high = pgm_read_word(&data[(nb * 2 * PI_BUF_SIZE) + 2 * i + 1]);
      low = pgm_read_word(&data[(nb * 2 * PI_BUF_SIZE) + 2 * i ]);
      pix_buffer[i] = (high<<8)+low;
    }
    tft.pushPixels(pix_buffer, np);
  }
 
  CS_H;
}

/*
void key_update(void){

    menu_botton.update();
    ok_botton.update();
    next_botton.update();

}*/

//lcd初始化函数
void lcd_init(void){

    tft.init();
    tft.setRotation(2);  //设置显示方向
    tft.fillScreen(TFT_WHITE);

    //screen.setColorDepth(8);

    //screen.createSprite(240,240);

    //tft.pushImage(0,0,180,180,biliTV);
    //screen.pushSprite(0,0);

    /*
    showImage(88,88,64,64,gImage_weather_ico);

    showImage(left_arrow_x,left_arrow_y,30,60,gImage_left_arrow_ico);
    showImage(right_arrow_x,right_arrow_y,30,60,gImage_right_arrow_ico);

    delay(1000);*/
}



