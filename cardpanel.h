#ifndef CARDPANEL_H
#define CARDPANEL_H

#include <QWidget>
#include "card.h"

class Player;

class CardPanel : public QWidget
{
    Q_OBJECT
public:
    explicit CardPanel(QWidget *parent = nullptr);


    // 设置获取图片和设置图片
    void setImage(QPixmap& front,QPixmap& back);
    QPixmap getImage();
    // 扑克牌显示哪一面
    void setFrontSide(bool flag);
    bool isFrontSide();

    // 记录窗口是否被选中
    void setSelect(bool flag);
    bool isSelect();

    // 扑克牌的的花色和点数
    void setCard(Card& card);
    Card getCard();

    // 扑克牌的所有者
    void setPlayer(Player* player);
    Player* getPlayer();
signals:


protected:
    void paintEvent(QPaintEvent *event) override;
private:
    QPixmap m_front;
    QPixmap m_back;
    bool m_isfront;
    bool m_isSelect;
    Card m_card;
    Player* m_player;
};


#endif // CARDPANEL_H
