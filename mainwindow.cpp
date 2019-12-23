#include "mainwindow.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
{

    this->setStyleSheet(QString(btnStyle));

    //性别选择
    sexLbl = new QLabel(tr("性别："));
    sexCbx = new QComboBox();
    sexCbx->addItem(tr("男"));
    sexCbx->addItem(tr("女"));
    sexCbx->setEditable(false);

    //身高输入
    heightLbl = new QLabel(tr("身高："));
    heightEdt = new QLineEdit(tr("0"));

    //活动状态选择
    actLbl = new QLabel(tr("活动状态："));
    actCbx = new QComboBox();
    actCbx->addItem(tr("活动"));
    actCbx->addItem(tr("卧床"));
    actCbx->setEditable(false);

    //结果显示
    energyLbl = new QLabel(tr("所需的能量："));
    eneResLbl = new QLabel(tr("0千卡"));
    int length = sizeof(powerLbl) / sizeof(powerLbl[0]);
    for (int i = 0; i < length; i++){
        powerLbl[i] = new QLabel(tr("%1：").arg(power[i].c_str()));
        resultLbl[i] = new QLabel(tr("0"));
    }

    //确认、清除按钮
    cfmBtn = new QPushButton(tr("确定"));
    clrBtn = new QPushButton(tr("清除"));

    //性别水平布局
    QHBoxLayout* sexLayout = new QHBoxLayout;
    sexLayout->addWidget(sexLbl);
    sexLayout->addWidget(sexCbx);
    //身高水平布局
    QHBoxLayout* heightLayout = new QHBoxLayout;
    heightLayout->addWidget(heightLbl);
    heightLayout->addWidget(heightEdt);
    //活动状态水平布局
    QHBoxLayout* actLayout = new QHBoxLayout;
    actLayout->addWidget(actLbl);
    actLayout->addWidget(actCbx);
    //输入框部分垂直布局
    QVBoxLayout* inputLayout = new QVBoxLayout;
    inputLayout->addLayout(sexLayout);
    inputLayout->addLayout(heightLayout);
    inputLayout->addLayout(actLayout);
    //输入框网格布局
    inputGbx = new QGroupBox(tr("输入"));
    inputGbx->setStyleSheet(QString(gbxStyle));
    inputGbx->setLayout(inputLayout);

    //结果框水平布局
    QHBoxLayout* energyLayout = new QHBoxLayout;
    energyLayout->addWidget(energyLbl);
    energyLayout->addWidget(eneResLbl);
    QHBoxLayout* resultHLayout[3];
    for (int i = 0; i < length; i++){
        resultHLayout[i] = new QHBoxLayout;
        resultHLayout[i]->addWidget(powerLbl[i]);
        resultHLayout[i]->addWidget(resultLbl[i]);
    }
    //结果框垂直布局
    QVBoxLayout* resultVLayout = new QVBoxLayout;
    resultVLayout->addLayout(energyLayout);
    for (int i = 0; i < length; i++){
        resultVLayout->addLayout(resultHLayout[i]);
    }
    //结果框网格布局
    resultGbx = new QGroupBox(tr("结果"));
    resultGbx->setStyleSheet(QString(gbxStyle));
    resultGbx->setLayout(resultVLayout);

    //按钮框水平布局
    QHBoxLayout* btnLayout = new QHBoxLayout;
    btnLayout->addWidget(cfmBtn);
    btnLayout->addWidget(clrBtn);

    //窗口垂直布局
    QVBoxLayout* mainVLayout = new QVBoxLayout;
    mainVLayout->addWidget(inputGbx);
    mainVLayout->addWidget(resultGbx);
    mainVLayout->addLayout(btnLayout);

    //设置窗口布局
    this->setLayout(mainVLayout);

    connect(this->cfmBtn,
            SIGNAL(clicked()),
            this,
            SLOT(cfmBtnSlot()));

    connect(this->clrBtn,
            SIGNAL(clicked()),
            this,
            SLOT(clrBtnSLot()));
}

MainWindow::~MainWindow()
{
    delete sexLbl;
    delete sexCbx;
    //身高
    delete heightLbl;
    delete heightEdt;
    //活动状态选择
    delete actLbl;
    delete actCbx;
    delete inputGbx;

    //结果框
    delete energyLbl;
    delete eneResLbl;
    int length = sizeof(powerLbl) / sizeof(powerLbl[0]);
    for (int i = 0; i < length; i++){
        delete powerLbl[i];
        delete resultLbl[i];
    }

    delete resultGbx;

    //确认、清除按钮
    delete cfmBtn;
    delete clrBtn;
    delete btnGbx;
}

//初始化输入框、结果框
int MainWindow::initData()
{
    heightEdt->setText(tr("0"));

    eneResLbl->setText(tr("0千卡"));
    int length = sizeof(powerLbl) / sizeof(powerLbl[0]);
    for (int i = 0; i < length; i++){
        resultLbl[i]->setText(tr("0"));
    }
    return 0;
}

int MainWindow::cfmBtnSlot()
{
    eneCal = new energyCal;
    int sex = this->sexCbx->currentIndex();
    float height = this->heightEdt->text().toFloat();
    int actv = this->actCbx->currentIndex();

    eneCal->setSex(sex);
    eneCal->setHeight(height);
    eneCal->setActvStat(actv);

    QVector<float> result = eneCal->caculate();

    this->eneResLbl->setText(tr("%1").arg((double)result[0]));
    int length = sizeof(powerLbl) / sizeof(powerLbl[0]);
    for (int i = 0; i < length; i++){
        resultLbl[i]->setText(tr("%1").arg((double)result[i + 1]));
    }


    return 0;
}

int MainWindow::clrBtnSLot()
{
    this->initData();
    return 0;
}

