

#ifndef _LCD_H
#define _LCD_H_

#include <SPI.h>
#include <TFT_eSPI.h> // Hardware-specific library

#define TFT_GREY 0x5AEB

//TFT_eSPI tft = TFT_eSPI();       // Invoke custom library


void lcd_init(void);//lcd初始化函数
void show_ui_list(void);//显示二级列表
void showImage(int32_t x, int32_t y, int32_t w, int32_t h, const uint16_t *data);//显示图片
void show_ui_home(void);//显示主页面
void show_astronaut_anim(void);//绘制太空人动画
void show_ui_weather(void);//显示天气详情页
void show_game_ui(void);//限制游戏详情页
void show_net_ui(void);//显示配网页面
void show_ui_clock(void);//正计时
void show_ui_video(void);//播放视频，暂时无功能
void show_ui_setup(void);//显示设置页面
void show_boot_ani(void);//开机动画


#endif