
#include "clock_Screen.h"
#include "../my_style.h"
#include "ico_imgs.h"


//char *time_hour_value = "20";
//char *time_min_value = "40";
//char *time_sec_value = "60";

extern lv_obj_t * clock_Screen;  //三级页面 闹钟，暂不提供闹钟设置


//�������ӣ��б���ʽ
void ui_clock_Screen(void)
{

    char *time_hour_value = "20";
    char *time_min_value = "40";
    char *time_sec_value = "60";
    //lv_style_set_bg_color(&style,lv_color_hex(0x000000));//��������ã����ʹ��Ĭ����ɫ��ɫ�������
    clock_Screen = lv_obj_create(NULL);

    lv_obj_add_style(clock_Screen,&style,0);
    lv_obj_align(clock_Screen,LV_ALIGN_CENTER,0,0);
    lv_obj_set_scrollbar_mode(clock_Screen, LV_SCROLLBAR_MODE_OFF);


    // ʱ�� Сʱ
    lv_obj_t *time_hour_text = lv_label_create(clock_Screen);
    lv_label_set_text(time_hour_text,time_hour_value);

    lv_obj_align(time_hour_text, LV_ALIGN_CENTER, -60, -10);
    lv_obj_add_style(time_hour_text,&my_font_style1,0);



    // ð��
     lv_obj_t *time_maohao1_text = lv_label_create(clock_Screen);
    lv_label_set_recolor(time_maohao1_text, true);
    lv_label_set_text(time_maohao1_text,":");
    lv_obj_add_style(time_maohao1_text,&my_font_style4,0);


    lv_obj_align(time_maohao1_text, LV_ALIGN_CENTER, -35, -10);


//    // ʱ�����
    lv_obj_t *time_min_text = lv_label_create(clock_Screen);
    lv_label_set_text(time_min_text,time_min_value);

    lv_obj_add_style(time_min_text,&my_font_style1,0);
    lv_obj_align(time_min_text, LV_ALIGN_CENTER, 10, -10);


    // ð��
    lv_obj_t *time_maohao2_text = lv_label_create(clock_Screen);
    lv_label_set_recolor(time_maohao2_text, true);
    lv_label_set_text(time_maohao2_text,":");
    lv_obj_add_style(time_maohao2_text,&my_font_style4,0);


    lv_obj_align(time_maohao2_text, LV_ALIGN_CENTER, 35, -10);


      // ��
    lv_obj_t *time_sec_text = lv_label_create(clock_Screen);
    lv_label_set_text(time_sec_text,time_sec_value);

    lv_obj_add_style(time_sec_text,&my_font_style1,0);

    lv_obj_align(time_sec_text, LV_ALIGN_CENTER, 80, -10);

    //ͼƬ��ť ��������ͣ

    LV_IMG_DECLARE(ico_start);
    LV_IMG_DECLARE(ico_stop);

    lv_obj_t* imgbtn1 = lv_imgbtn_create(clock_Screen);
    lv_obj_set_size(imgbtn1, 32, 32);
     lv_obj_align(imgbtn1, LV_ALIGN_CENTER, 0, 40);
    lv_imgbtn_set_src(imgbtn1,LV_IMGBTN_STATE_DISABLED, &ico_start,NULL,NULL);
    lv_imgbtn_set_src(imgbtn1, LV_IMGBTN_STATE_CHECKED_PRESSED, &ico_stop,NULL,NULL);


}
