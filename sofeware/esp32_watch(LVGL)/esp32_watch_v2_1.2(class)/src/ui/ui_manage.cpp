


#include "ui_manage.h"
#include "button.h"
#include "ui/my_style.h"
#include <lvgl.h>
//#include "lv_examples.h"
#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>
#include <Arduino.h>

#include "Page/ico_imgs.h"


#include "my_main_Screen.h"
#include "list_choice.h"

main_Screen_UI main_screen_ui;
list_Screen_UI list_screen_ui;

#include "Page/main_Screen.h"

#include "Page/aralm_ico_Screen.h"
#include "Page/aralm_Screen.h"

#include "Page/clock_ico_Screen.h"
#include "Page/clock_Screen.h"

#include "Page/tomato_ico_Screen.h"
#include "Page/tomato_Screen.h"

#include "Page/setting_ico_Screen.h"
//#include "Page/setting_Screen.h"

#include "Page/net_ico_Screen.h"
#include "Page/net_Screen.h"

//#include "Page/weather_ico_Screen.h"
#include "Page/weather_Screen.h"
//#include "Page/weather_ico_Screen1.h"

#include "Page/net_ico_Screen.h"
#include "Page/net_Screen.h"

#include "Page/logo_Screen.h"

uint8_t ui_index ;  // 用来记录当前UI界面位置
uint8_t ui_index_last;//上一次ui的位置
bool ui_updata_flag;
//Menu_table table[13] ;

lv_indev_t* indev_keypad;

lv_obj_t * Screen_ui[13] = {
    main_Screen,
    weather_ico_Screen,
    clock_ico_Screen,
    tomato_ico_Screen,
    aralm_ico_Screen,
    setting_ico_Screen,
    net_ico_Screen,
    weather_Screen,
    clock_Screen,
    aralm_Screen,
    tomato_Screen,
    setting_Screen,
    net_Screen,
    };

extern uint8_t BT_MENU_PIN;
extern uint8_t BT_OK_PIN;
extern uint8_t BT_NEXT_PIN;


// void (*current_operation_index)();


#define TFT_GREY 0x5AEB

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

/*Change to your screen resolution*/
static const uint16_t screenWidth  = 240;
static const uint16_t screenHeight = 240;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[ screenWidth * 10 ];




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
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init( &indev_drv );
    //实体按键初始化
    //lv_port_indev_init();
    //indev_drv.type = LV_INDEV_TYPE_POINTER;
    //ndev_drv.read_cb = my_touchpad_read;
    indev_drv.type = LV_INDEV_TYPE_KEYPAD;
    //indev_drv.read_cb = key_read;
    indev_keypad = lv_indev_drv_register( &indev_drv );

}



void ui_manage(void){
    if(digitalRead(BT_OK_PIN)==0){
            delay(30);
                if(digitalRead(BT_OK_PIN)==1){
                    //delay(1000);
                    ui_index=table[ui_index].enter;
            ui_updata_flag = true;
                    Serial.print("bt ok is pressed!\n\n");
                    
                }
            }

   if(digitalRead(BT_MENU_PIN)==0){
        delay(30);
            if(digitalRead(BT_MENU_PIN)==1){
                //delay(1000);
                 ui_index=table[ui_index].back;
                 ui_updata_flag = true;
                
                Serial.print("bt menu is pressed!\n\n");
                
            }
        }

if(digitalRead(BT_NEXT_PIN)==0){
        delay(30);
            if(digitalRead(BT_NEXT_PIN)==1){
                //delay(1000);
                 ui_index=table[ui_index].next;
                 ui_updata_flag = true;
                Serial.print("bt next is pressed!\n\n");
                
            }
        }
    
    if(ui_index_last!=ui_index){
        //current_operation_index=table[ui_index].current_operation;	//执行当前索引号所对应的功能函数
		//(*current_operation_index)();//执行当前操作函数
        Serial.printf(" the UI will change \n\n");

        ui_index_last = ui_index;

        //lv_scr_load_anim(Screen_ui[ui_index],LV_SCR_LOAD_ANIM_FADE_ON,100,0,false);

        switch(ui_index){
            case 0:
                lv_scr_load_anim(main_Screen,LV_SCR_LOAD_ANIM_FADE_ON,100,0,false);
                break;
            case 1:
                lv_scr_load_anim(tomato_ico_Screen,LV_SCR_LOAD_ANIM_FADE_ON,100,0,false);
                break;

            case 2:
                lv_scr_load_anim(weather_ico_Screen,LV_SCR_LOAD_ANIM_FADE_ON,100,0,false);
                break;
            case 3:
                lv_scr_load_anim(aralm_ico_Screen,LV_SCR_LOAD_ANIM_FADE_ON,100,0,false);
                break;
            case 4:
                lv_scr_load_anim(net_ico_Screen,LV_SCR_LOAD_ANIM_FADE_ON,100,0,false);
                break;
            case 5:
            
                lv_scr_load_anim(setting_ico_Screen,LV_SCR_LOAD_ANIM_FADE_ON,100,0,false);
                break;
            case 6:
                lv_scr_load_anim(tomato_Screen,LV_SCR_LOAD_ANIM_FADE_ON,100,0,false);
                break;
            case 7:
                lv_scr_load_anim(weather_Screen,LV_SCR_LOAD_ANIM_FADE_ON,100,0,false);
                break;
            case 8:
                lv_scr_load_anim(aralm_Screen,LV_SCR_LOAD_ANIM_FADE_ON,100,0,false);
                break;
            case 9:
                lv_scr_load_anim(net_Screen,LV_SCR_LOAD_ANIM_FADE_ON,100,0,false);
                break;
            case 10:
                lv_scr_load_anim(setting_Screen,LV_SCR_LOAD_ANIM_FADE_ON,100,0,false);
                break;
            
        }

        Serial.printf(" the UI index is %d \n\n",ui_index);
        
    }

   

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme); 
    
    my_style_init();

    main_screen_ui.init(main_Screen);
    //list_screen_ui.init(tomato_ico_Screen,tomato_ico,*"tomato");


    //ui_list_Screen();
    

    // ui_main_Screen();

    // ui_tomato_ico_Screen();
    // ui_tomato_Screen();

    // ui_weather_Screen();
    // ui_weather_ico_Screen();

    // ui_aralm_ico_Screen();
    // ui_aralm_Screen();

   
    // ui_net_ico_Screen();
    // ui_net_Screen();
    
    // ui_setting_ico_Screen();
    // ui_setting_Screen();

    // ui_logo_Screen();
    //lv_obj_add_flag(main_Screen,LV_OBJ_FLAG_HIDDEN);
    //lv_disp_load_scr(logo_Screen);

    // delay(1000);
    // delay(1000);
    // delay(1000);
    lv_scr_load_anim(main_Screen,LV_SCR_LOAD_ANIM_FADE_ON,100,0,false);

    

    
}

