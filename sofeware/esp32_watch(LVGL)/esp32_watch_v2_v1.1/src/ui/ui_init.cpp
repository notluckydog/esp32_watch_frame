


#include <lvgl.h>
//#include "lv_examples.h"
#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>
#include "button.h"

#define TFT_GREY 0x5AEB

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

/*Change to your screen resolution*/
static const uint16_t screenWidth  = 240;
static const uint16_t screenHeight = 240;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[ screenWidth * 10 ];

extern uint8_t BT_MENU_PIN;
extern uint8_t BT_OK_PIN;
extern uint8_t BT_NEXT_PIN;

lv_indev_drv_t indev_drv;// 输入设备，设置为键盘时，LVGL按键功能就可以使用

// extern Button menu_button;
// extern Button ok_button;
// extern Button next_button;

lv_indev_t* indev_keypad;


//TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight); /* TFT instance */

#if LV_USE_LOG != 0
/* Serial debugging */
void my_print(const char * buf)
{
    Serial.printf(buf);
    Serial.flush();
}
#endif

/* Display flushing */
void my_disp_flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p )
{
    uint32_t w = ( area->x2 - area->x1 + 1 );
    uint32_t h = ( area->y2 - area->y1 + 1 );

    tft.startWrite();
    tft.setAddrWindow( area->x1, area->y1, w, h );
    tft.pushColors( ( uint16_t * )&color_p->full, w * h, true );
    tft.endWrite();

    lv_disp_flush_ready( disp );
}


//按键扫描函数
bool my_key_scan1(uint8_t pin){
    if(digitalRead(pin)==0){
        delay(30);
            if(digitalRead(pin)==1){
                //delay(1000);
                return true;
                
            }else{
                //delay(1000);
                return false;
            }
        }
}

//按键扫描函数
uint8_t key_scan(){
  //menu按键被按下
    if(my_key_scan1(BT_MENU_PIN)){
      return 1;
    }

  //ok按键被按下
  if(my_key_scan1(BT_OK_PIN)){
      return 2;
    }

  //next按键被按下
  if(my_key_scan1(BT_NEXT_PIN)){
      return 3;
    }

    return 0;

}


//按键状态更新函数
static void key_read(lv_indev_drv_t * indev_driver, lv_indev_data_t * data){
    static uint32_t last_key = 0;
	  uint32_t act_key = key_scan();

    if(act_key != 0) {
      data->state = LV_INDEV_STATE_PR;
	    switch(act_key) {
	        case 1:
              //menu按键
	            act_key = LV_KEY_PREV;
	            data->state = LV_INDEV_STATE_PRESSED;	
	            break;
              //OK 按键
	        case 2:
	            act_key = LV_KEY_NEXT;
	            data->state = LV_INDEV_STATE_RELEASED;
	            data->enc_diff++;
	            break;
              //next按键
	        case 3:
	            act_key = LV_KEY_ENTER;
	            data->state = LV_INDEV_STATE_RELEASED;
	            data->enc_diff--;
	            break;
	    }
	    last_key = act_key;
	}else{
    data->state = LV_INDEV_STATE_REL;
  }
	data->key = last_key;

  //return false;


}


//LVGL 初始化
void MyDispalyInit(){
    lv_init();

#if LV_USE_LOG != 0
    lv_log_register_print_cb( my_print ); /* register print function for debugging */
#endif

    tft.begin();          /* TFT init */
    tft.setRotation( 0 ); /* Landscape orientation, flipped */
    tft.fillScreen(TFT_BLACK);//清屏

    lv_disp_draw_buf_init( &draw_buf, buf, NULL, screenWidth * 10 );

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init( &disp_drv );
    /*Change the following line to your display resolution*/
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    disp_drv.sw_rotate = 1;
    disp_drv.rotated = LV_DISP_ROT_180;
    lv_disp_drv_register( &disp_drv );

    /*Initialize the (dummy) input device driver*/
    //static lv_indev_drv_t indev_drv;
    lv_indev_drv_init( &indev_drv );
    //实体按键初始化
    //lv_port_indev_init();
    //indev_drv.type = LV_INDEV_TYPE_POINTER;
    //ndev_drv.read_cb = my_touchpad_read;
    indev_drv.type = LV_INDEV_TYPE_KEYPAD;
    indev_drv.read_cb = key_read;
    indev_keypad = lv_indev_drv_register( &indev_drv );

}