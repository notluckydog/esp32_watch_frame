

#ifndef _LIST_CHOICE_H_
#define _LIST_CHOICE_H_

#include <Arduino.h>
#include <lvgl.h>

class list_Screen_UI
{
    public:
        list_Screen_UI();
        ~list_Screen_UI();

        void init(lv_obj_t *Screen,lv_img_dsc_t ico,char text);
        void displayIco(lv_img_dsc_t ico);//显示图片
        void displayText(char text);//显示文字

    private:


    protected:

};

#endif