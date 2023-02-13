#ifndef _MY_STYLE_H_
#define _MY_STYLE_H_


#include <lvgl.h>


    //��Ļ��ʽ
   extern lv_style_t style;



/*  ������ ��ɫ 40������ ��ɫ���� ����ʱ��20:40 */
     extern lv_style_t my_font_style1;

 /*  С���� ��ɫ 16������ ��ɫ���� ���� 2022/10/22 */
     extern lv_style_t my_font_style2;

     /*  ������  ��*/
     extern lv_style_t my_font_style4;


    // // һ�����������ʽ 16������
     extern  lv_style_t my_nomal_style;

    //һ���Ե�С���壬��ɫ 14������
    extern  lv_style_t my_nomal_style1;


    //�б�style��
    extern lv_style_t style_list;

    //lv_style_set_border_width(&style_list, 0);


       //�б�������ʽ�����Ը���
       extern lv_style_t style_btn_list;


      void my_style_init();  //��ʽ��ʼ��


#endif // _MY_STYLE_H_
