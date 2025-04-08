#ifndef CARD_H
#define CARD_H

#include <QHash>
#include <QVector>

class Card{
public:
    // 花色
    enum CardSuit{
        Suit_Begin,
        Diamond,
        Clud,
        Heart,
        Spade,
        Suit_End
    };
    enum CardPoint{
        Card_Begin,
        Card_3,
        Card_4,
        Card_5,
        Card_6,
        Card_7,
        Card_8,
        Card_9,
        Card_10,
        Card_J,
        Card_Q,
        Card_K,
        Card_A,
        Card_2,
        Card_SJ,    // small_joker
        Card_BJ,    // big_joker
        Card_End,
    };
    Card();

    // 设置属性和获取属性
    void setCardSuit(CardSuit suit);
    void setCardPoint(CardPoint point);
    CardSuit suit() const ;
    CardPoint point() const ;
private:
    CardSuit _suit;
    CardPoint _point;

};

typedef QVector<Card> CardList;

//  全局函数声明
inline bool operator==(const Card &a, const Card &b)
{
    return a.point() == b.point() && a.suit() == b.suit();
}

inline uint qHash(const Card &key, uint seed = 0)
{
    return qHash(static_cast<int>(key.point()) * 10 + static_cast<int>(key.suit()), seed);
}

#endif // CARD_H
