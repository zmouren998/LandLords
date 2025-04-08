#include "cardpanel.h"
<<<<<<< HEAD

#include <QPixmap>
#include <QPainter>
#include <QMouseEvent>
=======
#include "card.h"

#include <QPainter>
>>>>>>> 0f463c2428bf133bff15332ce56532b8fbbc8355

CardPanel::CardPanel(QWidget *parent) : QWidget(parent)
{

}

void CardPanel::setImage(QPixmap &front, QPixmap &back)
{
    m_front = front;
<<<<<<< HEAD
    m_back = back;
=======
    m_back = back();
>>>>>>> 0f463c2428bf133bff15332ce56532b8fbbc8355
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
<<<<<<< HEAD

void CardPanel::mousePressEvent(QMouseEvent *event)
{

}
=======
>>>>>>> 0f463c2428bf133bff15332ce56532b8fbbc8355
