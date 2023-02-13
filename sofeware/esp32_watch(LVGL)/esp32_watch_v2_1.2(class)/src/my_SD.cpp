
#include "my_SD.h"


//SD卡模块引脚定义
uint8_t SD_CS = 5;
uint8_t SD_SCK = 18;
uint8_t SD_MOSI = 23;
uint8_t SD_MISO = 19;


//SD卡测试函数
//SD卡不工作
void SD_TEST(){


    //默认情况下，SPI外设都会使用VSPI这个通道，不同的外设一起工作时，
    //即使是使用不同的引脚，也会造成冲突

    /*知识点：
    ESP32 共有 4 个 SPI 控制器 SPI0、SPI1、SPI2、SPI3，用于连接支持 SPI 协议的设备。SPI0 控制器作为 cache 访问外部存储单元接口使用，SPI1 作为主机使用，SPI2 和 SPI3 控制器既可作为主机使用又可作为从机使用。作主机使用时，每个 SPI 控制器可以使用多个片选信号 (CS0 ~ CS2) 来连接多个 SPI 从机设备。
    SPI1 ~ SPI3 控制器共享两个 DMA 通道。
    SPI0 和 SPI1 控制器通过一个仲裁器共用一组信号总线，这组带前缀 SPI 的信号总线由 D、Q、CS0 ~ CS2、CLK、WP 和 HD 信号组成，如表 25 所示。
    相应地，控制器 SPI2 和 SPI3 分别使用带前缀 HSPI 和 VSPI 的信号总线。
    这些信号总线包含的输入输出信号线可以经过 GPIO 交换矩阵和 IO_MUX 模块实现与芯片管脚的映射
*/

    SPIClass MySPI(VSPI);//申明一个叫MySPI的 使用HSPI的总线对象 用来读写SD卡
 
  pinMode(SD_CS, OUTPUT);//SD卡CS脚
  digitalWrite(SD_CS, HIGH);//低电平选中，高电平不选中
 
 
  //自定义的SPI控制器的接线重新映射（就是实际的sd卡硬件接线）
  MySPI.begin(SD_SCK, SD_MISO, SD_MOSI);
  MySPI.setFrequency(1000000);//设置此SPI总线频率为1M  也可不用
 
 
 
 //用MySPI这个SPI总线去操作SD卡
  if( !SD.begin(SD_CS,MySPI) )
  {
        Serial.println("Card Mount Failed");//返回0失败
        return;
  }
 
  

    if(!SD.begin()){
        Serial.println("Card Mount Failed");
        return;
    }
    uint8_t cardType = SD.cardType();

    if(cardType == CARD_NONE){
        Serial.println("No SD card attached");
        return;
    }

    Serial.print("SD Card Type: ");
    if(cardType == CARD_MMC){
        Serial.println("MMC");
    } else if(cardType == CARD_SD){
        Serial.println("SDSC");
    } else if(cardType == CARD_SDHC){
        Serial.println("SDHC");
    } else {
        Serial.println("UNKNOWN");
    }

    uint64_t cardSize = SD.cardSize() / (1024 * 1024);
    Serial.printf("SD Card Size: %lluMB\n", cardSize);
}