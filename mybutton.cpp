#include "mybutton.h"

#include <QMouseEvent>
#include <QPixmap>
#include <QPainter>

MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{

}

void MyButton::setImage(QString normal, QString hover, QString press)
{
    m_hover = hover;
    m_press = press;
    m_normal = normal;
    m_pixmap.load(m_normal);
}

void MyButton::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        // 鼠标点击
        m_pixmap.load(m_press);
        update();
    }
    QPushButton::mousePressEvent(event);
}

void MyButton::enterEvent(QEvent *event)
{

    m_pixmap.load(m_hover);
    update();
    QPushButton::enterEvent(event);
}

void MyButton::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        // 鼠标点击
        m_pixmap.load(m_normal);
        update();
    }
    QPushButton::mouseReleaseEvent(event);
}

void MyButton::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);
    paint.drawPixmap(rect(),m_pixmap);
}

void MyButton::leaveEvent(QEvent *event)
{
    m_pixmap.load(m_normal);
    update();
    QPushButton::leaveEvent(event);
}
