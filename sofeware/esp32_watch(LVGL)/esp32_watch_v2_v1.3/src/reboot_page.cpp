

#include "page_config.h"


//该屏幕是用来实现开机动画的，
//开机流程：开机-》硬件初始化-》获取网络时间——》获取天气信息——》初始化屏幕
//使用开机动画，使得开机后不会黑屏
//暂时仅仅放置一个进度条

static lv_timer_t * reboot_timer;
 lv_obj_t * ui_bootBar;

lv_obj_t * reboot_Screen;
static uint32_t reboot_user_data = 0;



//定时器回调函数 用于控制进度条前进
void reboot_bar_timer(lv_timer_t * timer)
{
  /*Use the user_data*/
  uint32_t * reboot_user_data = (uint32_t *)timer->user_data;
  *reboot_user_data+=1;
  if(*reboot_user_data<=100)
  {
      lv_bar_set_value(ui_bootBar, *reboot_user_data, LV_ANIM_OFF);
  }
  else
  {
    //进度条走完之后 控制显示动画效果 进度条下沉 字体渐显
    //obj_set_anim(ui_bootBar, 10, 20, 800, 0, anim_set_y_cb,NULL,lv_anim_path_linear);
    //obj_set_anim(ui_bootLabel, 0, 255, 900, 0, anim_set_label_text_opa_cb, bar_label_sink_anim, lv_anim_path_linear);
    lv_timer_del(reboot_timer); //定时器没用了删除定时器
  }
}


void reboot_page(void ){

    reboot_Screen = lv_obj_create(NULL);

    lv_obj_add_style(reboot_Screen,&style,0);
    lv_obj_align(reboot_Screen,LV_ALIGN_CENTER,0,0);

    lv_scr_load_anim(reboot_Screen, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 300, 0, true);

    //显示logo

    lv_obj_t * logo_icon;
    logo_icon = lv_img_create(reboot_Screen);
    LV_IMG_DECLARE(my_logo);

    lv_img_set_src(logo_icon, &my_logo);
    lv_obj_set_size(logo_icon, 44, 44);

    lv_obj_align(logo_icon, LV_ALIGN_CENTER, 0, -30);
    //lv_obj_invalidate(logo_icon);

    //创建进度条
    //lv_obj_t * ui_bootBar;
    ui_bootBar = lv_obj_create(reboot_Screen);

    lv_bar_set_value(ui_bootBar, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_bootBar, 150);
    lv_obj_set_height(ui_bootBar, 5);


    lv_obj_set_align(ui_bootBar, LV_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_bootBar, lv_color_hex(0x4660A5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_bootBar, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_bootBar, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_bootBar, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    //进度条定时器
    reboot_timer = lv_timer_create(reboot_bar_timer, 8,  &reboot_user_data);

    


}