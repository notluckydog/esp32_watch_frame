
#ifndef _WATCH_H_
#define _WATCH_H_

#include <Arduino.h>
#include <lvgl.h>

// #include <TFT_eSPI.h> // Hardware-specific library
// #include <SPI.h>

// #define TFT_GREY 0x5AEB

// TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

// /*Change to your screen resolution*/
// static const uint16_t screenWidth  = 240;
// static const uint16_t screenHeight = 240;

// static lv_disp_draw_buf_t draw_buf;
// static lv_color_t buf[ screenWidth * 10 ];

// lv_indev_drv_t indev_drv;// 输入设备，设置为键盘时，LVGL按键功能就可以使用

// lv_indev_t* indev_keypad;


class Watch{

    public:
        Watch(void);
        ~Watch(void);

        void init(void);
        void begin(void);
        void sleep(void);//睡眠模式


    private:

    protected:

};


#endif

