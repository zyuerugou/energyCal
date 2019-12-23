#ifndef ENERGYCAL_H
#define ENERGYCAL_H

#include <QVector>
#include "head.h"

class energyCal
{
public:
    energyCal();

    //设置性别
    void setSex(int sex);
    //设置身高
    void setHeight(float height);
    //设置活动状态
    void setActvStat(int actvStat);
    //计算
    QVector<float> caculate();

private:
    //性别
    int sex;
    //身高
    float height;
    //活动状态
    int actvStat;


};

#endif // ENERGYCAL_H
