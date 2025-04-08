#include "cardpanel.h"

#include <QPixmap>
#include <QPainter>
#include <QMouseEvent>

CardPanel::CardPanel(QWidget *parent) : QWidget(parent)
{

}

void CardPanel::setImage(QPixmap &front, QPixmap &back)
{
    m_front = front;
    m_back = back;
    setFixedSize(m_front.size());

    update();   // 设置图片之后重新绘制图片
}

QPixmap CardPanel::getImage()
{
    return m_front;
}

void CardPanel::setFrontSide(bool flag)
{
    m_isfront = flag;
}

bool CardPanel::isFrontSide()
{
    return m_isfront;
}

void CardPanel::setSelect(bool flag)
{
    m_isSelect = flag;
}

bool CardPanel::isSelect()
{
    return m_isSelect;
}

void CardPanel::setCard(Card &card)
{
    m_card = card;
}

Card CardPanel::getCard()
{
    return m_card;
}

void CardPanel::setPlayer(Player *player)
{
    m_player = player;
}

Player *CardPanel::getPlayer()
{
    return m_player;
}

void CardPanel::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);
    // 根据正面还是反面
    if(m_isfront)
        paint.drawPixmap(rect(),m_front);
    else
        paint.drawPixmap(rect(),m_back);
}

void CardPanel::mousePressEvent(QMouseEvent *event)
{

}
