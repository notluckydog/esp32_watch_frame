

#include "watch.h"

#include"button.h"
#include "my_style.h"

extern lv_obj_t * Screen;
extern  Button ok_button;
extern  Button menu_button;
extern  Button next_button;

#include <lvgl.h>
#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>

#define TFT_GREY 0x5AEB

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

/*Change to your screen resolution*/
static const uint16_t screenWidth  = 240;
static const uint16_t screenHeight = 240;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[ screenWidth * 10 ];

lv_indev_drv_t indev_drv;// 输入设备，设置为键盘时，LVGL按键功能就可以使用

lv_indev_t* indev_keypad;



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
uint8_t key_scan(void){
//menu按键被按下
    if(menu_button.getStatus()==0){
      return 1;
    }

  //ok按键被按下
  if(ok_button.getStatus()==0){
      return 2;
    }

  //next按键被按下
  if(next_button.getStatus()==0){
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




Watch::Watch(void){

}

Watch::~Watch(void){

}

void Watch::init(void){
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
    indev_drv.type = LV_INDEV_TYPE_ENCODER;
    indev_drv.read_cb = key_read;
    indev_keypad = lv_indev_drv_register( &indev_drv );

}


void Watch::begin(void){
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme); 

    my_style_init();

    // lv_style_t style_display;
    // lv_style_init(&style_display);

    // lv_style_set_bg_color(&style_display,lv_color_hex(0xFFFFFF));
    // lv_style_set_radius(&style_display,120);
    // lv_style_set_bg_opa(&style_display,LV_OPA_100);
    // lv_style_set_width(&style_display,240);
    // lv_style_set_height(&style_display,240);

    // Screen = lv_obj_create(NULL);
    
    // lv_scr_load_anim(Screen,LV_SCR_LOAD_ANIM_FADE_ON,100,0,false);



}

void Watch::sleep(void){

  
}