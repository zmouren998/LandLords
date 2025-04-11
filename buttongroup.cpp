#include "buttongroup.h"
#include "ui_buttongroup.h"

#include "mybutton.h"

ButtonGroup::ButtonGroup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ButtonGroup)
{
    ui->setupUi(this);
}

ButtonGroup::~ButtonGroup()
{
    delete ui;
}

void ButtonGroup::initButton()
{
    // 开始游戏
    ui->start_btn->setImage(":/img/start-1.png",":/img/start-2.png",":/img/start-3.png");
    // 出牌
    ui->play_btn->setImage(":/img/chupai_btn-1.png",":/img/chupai_btn-2.png",":/img/chupai_btn-3.png");
    ui->play_btn_2->setImage(":/img/chupai_btn-1.png",":/img/chupai_btn-2.png",":/img/chupai_btn-3.png");
    // 不要
    ui->pass_btn->setImage(":/img/pass_btn-1.png",":/img/pass_btn-2.png",":/img/pass_btn-3.png");
    // 不抢
    ui->giveup_btn->setImage(":/img/buqiang-1.png",":/img/buqiang-2.png",":/img/buqiang-3.png");
    // 1，2，3分
    ui->one_btn->setImage(":/img/1fen-1.png",":/img/1fen-2.png",":/img/1fen-3.png");
    ui->two_btn->setImage(":/img/2fen-1.png",":/img/2fen-2.png",":/img/2fen-3.png");
    ui->three_btn->setImage(":/img/3fen-1.png",":/img/3fen-2.png",":/img/3fen-3.png");

    // 将所有按钮添加到集合中，遍历集合设置按钮大小
    QVector<MyButton*> btns;
    btns << ui->start_btn << ui->play_btn<< ui->play_btn_2
         << ui->pass_btn << ui->giveup_btn << ui->one_btn
         << ui->two_btn << ui->three_btn;
    for (int i = 0;i < btns.size();++i){
        btns[i]->setFixedSize(90,45);
    }

}
