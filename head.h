#ifndef HEAD_H
#define HEAD_H

#include <string>

enum {
     male = 0   //男
    ,female = 1 //女
};

static const float heavyCal[2] = {
     -100.0f
    ,-105.0f
};

enum {
     active = 0 //活动
    ,quiet  = 1 //卧床
};

static const float eneryCal[2] = {
     25.0f
    ,30.0f
};


static const std::string power[3] {
     "能全力"
    ,"瑞代"
    ,"百普力"
};

static const float powerCal[3] ={
     420.0f
    ,450.0f
    ,500.0f
};


static float rate = 2.0f / 3.0f;

const char btnStyle[] = "QPushButton{\
                                font-size:20px;\
                                font-weight:bold;\
                                border:0;\
                                width:60px;\
                                height:50px;\
                                color:#ccc;\
                                background-color:rgba(80,80,80,80);\
                                border-radius:5px}"\
                        "QPushButton:hover {\
                                background-color:rgba(100,100,100,100);\
                                color:#fff}"\
                        "QPushButton:pressed{\
                                background-color:rgb(85, 170, 255);\
                                border-style: inset; }";

const char gbxStyle[] = "QGroupBox {\
                                    background-color: rgba(80,80,80,80);\
                                    color:#ccc}";

#endif // HEAD_H
