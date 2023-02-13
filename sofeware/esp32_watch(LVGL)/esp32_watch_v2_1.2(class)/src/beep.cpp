

#include "beep.h"

Beep::~Beep(){

};


Beep::Beep(uint8_t beep_pin,uint8_t freq,uint8_t ledChannel){
    _freq =freq;
    _ledChannel = ledChannel;

    if(beep_pin<40&&beep_pin>0){
    _beep_pin=beep_pin;
     
    }else{
        Serial.print("invalid beep pin number\n\n");
    }

    ledcSetup(_ledChannel,_freq, _resolution);
    ledcAttachPin(_beep_pin, _ledChannel);

}

void Beep::setFreq(uint8_t freq){
    _freq = freq;
    ledcSetup(_ledChannel,_freq, _resolution);

}

void Beep::setResolution(uint8_t resolution){
    _resolution =resolution;
    ledcSetup(_ledChannel,_freq, _resolution);
}


void Beep::setDutyCycle(uint8_t dutyCycle){
    _dutyCycle =dutyCycle;
     ledcWrite(_ledChannel, _dutyCycle);

}

void Beep::on(void){
    ledcWrite(_ledChannel, _dutyCycle);
}

void Beep::off(void){
    ledcWrite(_ledChannel, 255);
}