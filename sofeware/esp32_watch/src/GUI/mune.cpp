

#include "menu.h"

/*----目录节点----*/
 Menu_t *Time_Menu;
 Menu_t *Dialogo;
/*----------------*/

/*----控制句柄----*/
 Menu_t *weather_menu; // 二级菜单，天气
 Menu_t *time_menu;//二级菜单，计时器
 Menu_t *game_menu;//二级菜单，游戏
 Menu_t *video_menu; //二级菜单，视频
 Menu_t *setup_menu;//二级菜单，设置
 Menu_t *Back;
/*----------------*/


//三级菜单
//天气菜单
Menu_t *w_today_menu;//三级菜单，今天天气
Menu_t *w_nextday_menu;//三级菜单，明天天气详情
Menu_t *w_afterday_menu;//三级菜单，后天天气详情
// Menu_t *Test_4;

//计时器菜单
 Menu_t *t_P_menu;//三级菜单，正计时


//游戏菜单
 Menu_t *g_dinosaur_menu;//三级菜单，小恐龙游戏


//视频菜单
 Menu_t *v_badapple_menu;//三级菜单，播放badapple

//设置菜单
 Menu_t *s_setup_menu;//设置详情页面



/*----功能节点----*/
 Menu_t *Pre_SelectMune;
 Menu_t *CurrentMune;
 Menu_t *SelectMune;
/*----------------*/

 uint32_t Time_Count;
 uint32_t Time_Count_Bak;

 