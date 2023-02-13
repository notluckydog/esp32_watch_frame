

#include "page_config.h"
//#include "anim.h"

static uint32_t user_data = 0;
static lv_obj_t * ui_bootPanel;
static lv_obj_t * ui_bootLabel;
static lv_obj_t * ui_bootBar;
static lv_obj_t * ui_netLabel;
static lv_obj_t * ui_netImage; 
static lv_timer_t * timer;

 
    

//定时器回调函数 用于控制进度条前进
void my_timer(lv_timer_t * timer)
{
  /*Use the user_data*/
  uint32_t * user_data = (uint32_t *)timer->user_data;
  *user_data+=1;
  if(*user_data<=100)
  {
      lv_bar_set_value(ui_bootBar, *user_data, LV_ANIM_OFF);
  }
  else
  {
    //进度条走完之后 控制显示动画效果 进度条下沉 字体渐显
    // obj_set_anim(ui_bootBar, 10, 20, 800, 0, anim_set_y_cb,NULL,lv_anim_path_linear);
    // obj_set_anim(ui_bootLabel, 0, 255, 900, 0, anim_set_label_text_opa_cb, bar_label_sink_anim, lv_anim_path_linear);
    lv_timer_del(timer); //定时器没用了删除定时器
  }
}


void alarm_page(void){

    //创建画板 承托各个显示元素
    ui_bootPanel = lv_obj_create(lv_scr_act());
    lv_obj_set_width(ui_bootPanel, 240);
    lv_obj_set_height(ui_bootPanel, 240);
    lv_obj_set_align(ui_bootPanel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_bootPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_bootPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_bootPanel, lv_color_hex(0x4660A5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_bootPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_bootPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);


    //创建文字logo
    ui_netLabel = lv_label_create(ui_bootPanel);
    lv_obj_set_width(ui_netLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_netLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_netLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_netLabel, "WiFi Connecting...");
    lv_obj_set_style_text_color(ui_netLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_netLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_text_font(ui_netLabel, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_netLabel,0,0);  //透明度为0  不让其显现

    //创建文字logo
    ui_bootLabel = lv_label_create(ui_bootPanel);
    lv_obj_set_width(ui_bootLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_bootLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_bootLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_bootLabel, "Z-Clock");
    lv_obj_set_style_text_color(ui_bootLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_bootLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_text_font(ui_bootLabel, &lv_font_montmy_36, LV_PART_MAIN | LV_STATE_DEFAULT);

    //创建进度条
    ui_bootBar = lv_bar_create(ui_bootPanel);
    lv_bar_set_value(ui_bootBar, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_bootBar, 150);
    lv_obj_set_height(ui_bootBar, 5);
    lv_obj_set_y(ui_bootBar, 10);
    lv_obj_set_align(ui_bootBar, LV_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_bootBar, lv_color_hex(0x4660A5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_bootBar, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_bootBar, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_bootBar, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    //进度条定时器

    lv_scr_load_anim(ui_bootPanel, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 300, 0, true);
   
    timer = lv_timer_create(my_timer, 8,  &user_data);



}