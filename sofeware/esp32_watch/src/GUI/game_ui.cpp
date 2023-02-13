

#include "lcd.h"
#include "dinosaur_pic.h"
#include "key.h"
#include "pic_ico.h"

extern TFT_eSPI tft;
extern TFT_eSprite screen ;

extern Bounce2::Button menu_botton;
extern  Bounce2::Button ok_botton;
extern Bounce2::Button next_botton;

extern void (*gui_func)(void);//定义函数指针，指向特定函数

static uint8_t D_index = 0;//恐龙图标绘制第几章图片
const uint16_t *d_p;//用来保存只想数组的指针

uint8_t D_targer_x =30;//恐龙绘制图标X坐标
uint8_t D_targer_y =117;//恐龙绘制图标X坐标

uint8_t Z_targer_x = 200;//障碍物绘制图标X坐标
uint8_t Z_targer_y = 100;//障碍物绘制图标X坐标

uint8_t W_targer_x = 240;//云朵绘制图标X坐标
uint8_t W_targer_y =40;//云朵绘制图标Y坐标

uint8_t z_index = 1;//屏幕上障碍的数量

bool start_flag = true;//开始标志
bool jump_flag = false;//跳跃标志

uint8_t game_speed =5;// 游戏速度

uint32_t now_score = 0;// 现在的分数
uint32_t max_score = 0;//最高的分数

unsigned long game_key_previousMilis =0;//使用mills函数来实现精准计时，定时器功能
unsigned long game_previousMilis =0;

bool game_first = false;

//恐龙动作、跳
uint8_t D_jump(void){

    static uint16_t height = 0;
    static uint8_t  dire = 0;//恐龙是上升还是下降
    uint8_t speed[]={1,1,3,3,4,4,5,6,7};
    static uint8_t spdnum=sizeof(speed)-1;
    if(jump_flag){
        if(dire ==0){
        //上升
        D_targer_y += speed[spdnum];
        spdnum--;
        //D_targer_y+=height;

        }
        if(dire =1){
        //下降
        D_targer_y -= speed[spdnum];//下降的速度
		spdnum++;
		if(spdnum>sizeof(speed)-1){
            spdnum=sizeof(speed)-1;
        }
        if(D_targer_y ==117 ){
            jump_flag = false;
        }

        }
    }

    

    
}

void show_d_pic(void){
    //节省空间，使用一个方块来代表恐龙
    //tft.drawRect(D_targer_x,D_targer_y,30,33,TFT_WHITE);
    tft.fillRect(D_targer_x,D_targer_y,15,33,TFT_WHITE);
}
void showD_pic(void){
    //绘制恐龙图标
        switch(D_index)
        {
            case 0:
                showImage(D_targer_x,D_targer_y,30,33,gImage_D_01);
                break;
            case 1:
                showImage(D_targer_x,D_targer_y,30,33,gImage_D_02);
                break;
            
            case 2:
                showImage(D_targer_x,D_targer_y,30,33,gImage_D_03);
                break;

            case 3:
                showImage(D_targer_x,D_targer_y,30,33,gImage_D_04);
                break;
            case 4:
                showImage(D_targer_x,D_targer_y,30,33,gImage_D_05);
                break;
            
            case 5:
                
                showImage(D_targer_x,D_targer_y,30,33,gImage_D_06);
                break;
            default:
                showImage(D_targer_x,D_targer_y,30,33,gImage_D_01);
            }
}

//绘制障碍物
void showZ_pic(void){
    //绘制障碍物图片
    showImage(Z_targer_x,Z_targer_y,14,30,gImage_Z_01);

    /*for(z_index;z_index>=0;z_index--){
        //障碍物大小 14X30
        showImage(Z_targer_x+z_index*14,Z_targer_y,14,30,gImage_Z_01);
        tft.drawre
    }*/
}

//绘制云朵
void showW_pic(void){
    showImage(W_targer_x,W_targer_y,32,32,gImage_W_01);
}

//坐标更新函数
void live(void){
   
    if(start_flag){
        //障碍物
    Z_targer_x-=game_speed;
    if(Z_targer_x<0){
        Z_targer_x = 200;
    }
    
    
    //云朵
    W_targer_x -= game_speed;
     if(W_targer_x<0){
        W_targer_x = 200;
        Serial.print("good!");
    }

    //恐龙
    //D_targer_x +=game_speed;

    //分数更新
    now_score+=game_speed;

    D_jump();
    }
    
    


}

//失败了
void die(void){
    //游戏暂停
    start_flag = false;
    //判断分数
    if(now_score >max_score){
        now_score  = max_score;
    }

    tft.setCursor(100,60);
    tft.setTextColor(TFT_WHITE,TFT_BLACK);//设置字体颜色 背景色
    tft.setTextSize(2);
    tft.print("you fail !");
}

//判断是否发生碰撞
void is_collision(void){
    //坐标检测
    if(Z_targer_x>D_targer_x&&Z_targer_x<D_targer_x+32){
        if(D_targer_y+32<Z_targer_y){
            start_flag = false;
            die();
        }
    }
}



//绘制分数
void show_score(void){
    //绘制现在的分数
    tft.setCursor(100,20);
    tft.setTextColor(TFT_WHITE,TFT_BLACK);//设置字体颜色 背景色
    tft.setTextSize(1);
    tft.printf("now score: %d",now_score);


    //绘制最高分数
    tft.setCursor(100,40);
    //tft.setTextColor(TFT_WHITE,TFT_BLACK);//设置字体颜色 背景色
    //tft.setTextSize(1);
    tft.printf("max score: %d",max_score);
}
//按键更新函数
void key_game_hander(void){
    if(ok_botton.pressed()){
        //start_flag = !start_flag;
        //将 you die 这句话覆盖掉
        tft.fillRect(100,60,30,20,TFT_BLACK);
        Serial.print("ok bt is pressed!\n");
    }
    if(next_botton.pressed()){
        //跳跃键
        //D_jump();
        jump_flag = true;
        Serial.print("next bt is pressed!\n");
    }
    if(menu_botton.pressed()){
        //退出游戏
        tft.fillCircle(120,120,120,TFT_WHITE);
        game_first = false;
        Serial.print("menu bt is pressed!\n");
        gui_func = show_ui_list;
    }
}

//绘制开始或者停止图标
void show_flag(void){
    if(start_flag){
            //32X32
        showImage(104,180,32,32,gImage_start_ico);
    }else{
        showImage(104,180,32,32,gImage_stop_ico);
    }
}

//绘制地面
void show_ground(void){
    //绘制地面 仅一条线
    tft.drawLine(0,140,240,140,TFT_WHITE);
}

//显示恐龙小游戏
void show_game_ui(void){

        if(game_first == false){
            tft.fillScreen(TFT_BLACK);
            game_first = true;
        }
        unsigned long currentMillis = millis(); // store the current time

        if(currentMillis - game_key_previousMilis >=20){
            game_key_previousMilis = currentMillis;
            key_game_hander();
        }

        if(currentMillis - game_previousMilis >=300){
            //tft.fillScreen(TFT_BLACK);
            game_previousMilis = currentMillis;

            //绘制地面
            show_ground();

            //绘制障碍物图片
            showZ_pic();
            //Serial.print("2");

            //绘制天气图片
            showW_pic();
            //Serial.print("3");

            //绘制开始图标
            show_flag();
            //Serial.print("4");

            //绘制分数
            show_score();
            //Serial.print("6");
            
            //绘制恐龙图片
            //showD_pic();
            //showImage(D_targer_x,D_targer_y,30,33,gImage_D_01);
            show_d_pic();
            //Serial.print("1");

            live();

            //判断是否碰撞
            is_collision();
            //Serial.print("5");


            
            
            //delay(1000);

        }
        
    
   
    
}