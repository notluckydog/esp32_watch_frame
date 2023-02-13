

#include "lcd.h"
#include "pic_ico.h"

extern TFT_eSPI tft ; 

void show_boot_ani(void){
    
    showImage(56,76,128,89,gImage_my_logo);
}
