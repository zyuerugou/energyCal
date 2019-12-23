#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QGroupBox>

#include "head.h"
#include "energycal.h"

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //输入框、结果框初始化
    int initData();

public slots:

    //确认按钮槽函数
    int cfmBtnSlot();
    //清除按钮槽函数
    int clrBtnSLot();

private:

    //性别选择
    QLabel* sexLbl;
    QComboBox* sexCbx;
    //身高
    QLabel* heightLbl;
    QLineEdit* heightEdt;
    //活动状态选择
    QLabel* actLbl;
    QComboBox* actCbx;
    QGroupBox* inputGbx;

    //结果框
    QLabel* energyLbl;
    QLabel* eneResLbl;
    QLabel* powerLbl[3];
    QLabel* resultLbl[3];
    QGroupBox* resultGbx;

    //确认、清除按钮
    QPushButton* cfmBtn;
    QPushButton* clrBtn;
    QGroupBox* btnGbx;

    energyCal* eneCal;
};
#endif // MAINWINDOW_H
