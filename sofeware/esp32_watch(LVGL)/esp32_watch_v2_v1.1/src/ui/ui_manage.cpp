


#include "ui_manage.h"
#include "button.h"
#include "ui/my_style.h"

#include "ntp_time.h"

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

//#include "Page/logo_Screen.h"



uint8_t ui_index ;  // 用来记录当前UI界面位置
uint8_t ui_index_last;//上一次ui的位置
bool ui_updata_flag;
extern lv_indev_drv_t indev_drv;//控制按键是否有效，目前仅在setting页面中有效
extern lv_indev_t* indev_keypad;
//Menu_table table[13] ;

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

//按键扫描函数
static bool my_key_scan(uint8_t pin){
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
static uint8_t key_scan(){
  //menu按键被按下
    if(my_key_scan(BT_MENU_PIN)){
      return 1;
    }

  //ok按键被按下
  if(my_key_scan(BT_OK_PIN)){
      return 2;
    }

  //next按键被按下
  if(my_key_scan(BT_NEXT_PIN)){
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

//按键状态更新函数
static void key_read_update(lv_indev_drv_t * indev_driver, lv_indev_data_t * data){
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

void ui_manage(void){
    if(digitalRead(BT_OK_PIN)==0){
            delay(40);
                if(digitalRead(BT_OK_PIN)==1){
                    //delay(1000);
                    ui_index=table[ui_index].enter;
                    ui_updata_flag = true;
                    Serial.print("bt ok is pressed!\n\n");
                    
                }
            }

   if(digitalRead(BT_MENU_PIN)==0){
        delay(40);
            if(digitalRead(BT_MENU_PIN)==1){
                //delay(1000);
                 ui_index=table[ui_index].back;
                 ui_updata_flag = true;
                
                Serial.print("bt menu is pressed!\n\n");
                
            }
        }

if(digitalRead(BT_NEXT_PIN)==0){
        delay(40);
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
                indev_drv.type = LV_INDEV_TYPE_KEYPAD;
                indev_drv.read_cb = key_read;
                indev_keypad = lv_indev_drv_register( &indev_drv );
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

    //ui_list_Screen();
    
    ui_main_Screen();

    ui_tomato_ico_Screen();
    ui_tomato_Screen();

    ui_weather_Screen();
    ui_weather_ico_Screen();

    ui_aralm_ico_Screen();
    ui_aralm_Screen();


    ui_net_ico_Screen();
    ui_net_Screen();
    
    ui_setting_ico_Screen();
    ui_setting_Screen();

    //ui_logo_Screen();
    //lv_obj_add_flag(main_Screen,LV_OBJ_FLAG_HIDDEN);
    //lv_disp_load_scr(logo_Screen);

    //delay(1000);
    //delay(1000);
    //delay(1000);
    lv_scr_load_anim(setting_Screen,LV_SCR_LOAD_ANIM_FADE_ON,100,0,false);

    

    
}

//主页面 时间更新任务
void GUI_time_update_task(void *p){

    while(1){
        TickType_t xLastWakeTime = xTaskGetTickCount();
        getTime();
        const TickType_t xFrequency = 1000; // 间隔 3000 ticks = 3 seconds
      ui_main_Screen_DisplayTime();
      vTaskDelayUntil(&xLastWakeTime,xFrequency);
    }

}