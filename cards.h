#ifndef CARDS_H
#define CARDS_H


#include "card.h"
#include <QSet>


// 创建牌的集合类
class Cards
{
public:

    enum SortType{
        Asc,
        Desc,
        NoSort
    };
    Cards();

    // 添加card
    void add(const Card& card);
    void add(const Cards& cards);
    // 删除card
    void remove(const Card& card);
    void remove(const Cards& cards);

    // 重载运算符 <<
    Cards& operator<<(const Card& other);
    Cards& operator<<(const Cards& other);

    // 当前牌的数量
    int CardsNum();
    // 判断牌数是否为空
    bool CardsIsEmpty();
    // 清空牌
    void ClearCards();

    // 最大点数
    Card::CardPoint maxPoint();
    // 最小点数
    Card::CardPoint minPoint();
    // 指定点数的个数
    int pointCount(Card::CardPoint point);
    // 某张牌是否在集合中
    bool contains(const Card& card);
    bool contains(const  Cards& cards);

    // 随机发出一张牌
    Card takeRandCard();

    // 对牌进行排序
    CardList toCardList(SortType type = Desc);
private:
    QSet<Card> m_cards;
};

#endif // CARDS_H
