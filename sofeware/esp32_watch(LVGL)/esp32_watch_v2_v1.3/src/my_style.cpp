
#include "my_style.h"

 //��Ļ��ʽ
lv_style_t style;



/*  ������ ��ɫ 40������ ��ɫ���� ����ʱ��20:40 */
lv_style_t my_font_style1;

 /*  С���� ��ɫ 16������ ��ɫ���� ���� 2022/10/22 */
lv_style_t my_font_style2;

     /*  ������  ��*/
lv_style_t my_font_style4;


    // // һ�����������ʽ 16������
 lv_style_t my_nomal_style;

    //һ���Ե�С���壬��ɫ 14������
 lv_style_t my_nomal_style1;


    //�б�style��
 lv_style_t style_list;

    //lv_style_set_border_width(&style_list, 0);


       //�б�������ʽ�����Ը���
 lv_style_t style_btn_list;



void  my_style_init()
{
lv_style_init(&style);
lv_style_set_bg_color(&style,lv_color_hex(0x000000));

lv_style_set_radius(&style,120);
lv_style_set_bg_opa(&style,LV_OPA_100);
lv_style_set_width(&style,240);
lv_style_set_height(&style,240);
lv_style_set_border_width(&style, 0);

/*  ������ ��ɫ 40������ ��ɫ���� ����ʱ��20:40 */
    //static lv_style_t my_font_style1;
    lv_style_init(&my_font_style1);
    //lv_style_set_width(&my_font_style1,80);
    lv_style_set_height(&my_font_style1,40);
    lv_style_set_text_color(&my_font_style1,lv_palette_main(LV_PALETTE_YELLOW));
    lv_style_set_text_font(&my_font_style1, &lv_font_montserrat_40);
    lv_style_set_border_width(&my_font_style1, 0);
    lv_style_set_bg_color(&my_font_style1,lv_color_hex(0x000000));

    /*  С���� ��ɫ 16������ ��ɫ���� ���� 2022/10/22 */
    //static lv_style_t my_font_style2;
    lv_style_init(&my_font_style2);
    lv_style_set_width(&my_font_style2,16);
    lv_style_set_height(&my_font_style2,16);
    lv_style_set_text_color(&my_font_style2,lv_palette_main(LV_PALETTE_YELLOW));

     /*  ������  ��*/
    //static lv_style_t my_font_style4;
    lv_style_init(&my_font_style4);
    lv_style_set_width(&my_font_style4,20);
    lv_style_set_height(&my_font_style4,40);
    lv_style_set_text_color(&my_font_style4,lv_palette_main(LV_PALETTE_YELLOW));
    lv_style_set_text_font(&my_font_style4, &lv_font_montserrat_40);


    // // һ�����������ʽ 16������
    //static lv_style_t my_nomal_style;
    lv_style_init(&my_nomal_style);

    lv_style_set_height(&my_nomal_style,16);
    lv_style_set_text_color(&my_nomal_style,lv_palette_main(LV_PALETTE_YELLOW));
    lv_style_set_text_font(&my_nomal_style, &lv_font_montserrat_16);

    //һ���Ե�С���壬��ɫ 14������
    //static lv_style_t my_nomal_style1;
    lv_style_init(&my_nomal_style1);

    lv_style_set_height(&my_nomal_style1,14);
    lv_style_set_text_color(&my_nomal_style1,lv_color_hex(0xFFFFFF));
    lv_style_set_text_font(&my_nomal_style1, &lv_font_montserrat_14);


    //�б�style��
    //static lv_style_t style_list;
    lv_style_init(&style_list);
    lv_style_set_bg_color(&style_list,lv_color_hex(0x000000));
    lv_style_set_radius(&style_list,6);
    //lv_style_set_bg_opa(&style_list,LV_OPA_100);
    lv_style_set_width(&style_list,150);
    lv_style_set_height(&style_list,190);
    lv_style_set_border_width(&style_list, 0);


       //�б�������ʽ�����Ը���
    //static lv_style_t style_btn_list;
    lv_style_init(&style_btn_list);
    lv_style_set_radius(&style_btn_list, 0);
    lv_style_set_bg_opa(&style_btn_list, LV_OPA_10);
    lv_style_set_bg_color(&style_btn_list, lv_color_hex(0x000000));
    lv_style_set_text_color(&style_btn_list, lv_color_white());



}


