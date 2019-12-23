#include "energycal.h"

//初始化
energyCal::energyCal()
{
    this->sex = 'M';
    this->height = 0.0f;
    this->actvStat = active;
}

//设置性别
void energyCal::setSex(int sex)
{
    this->sex = sex;
}

//设置身高
void energyCal::setHeight(float height)
{
    this->height = height;
}

//设置活动状态
void energyCal::setActvStat(int actvStat)
{
    this->actvStat = actvStat;
}

/*
 * function:  计算所需能量和三种能量液数量
 * return:    所需的能量和三种能量液数量
 * */
QVector<float> energyCal::caculate()
{
    float heavy = this->height + heavyCal[this->sex];
    float energy = heavy * eneryCal[this->actvStat];

    QVector<float> result;
    result.append(energy);

    int length = sizeof(powerCal) / sizeof(*powerCal);
    for (int i = 0; i < length; i++){
        float tmp = energy * rate / powerCal[i];
        result.append(tmp);
    }

    return result;
}

