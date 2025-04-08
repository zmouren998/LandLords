#ifndef CARD_H
#define CARD_H


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
    CardSuit suit();
    CardPoint point();
private:
    CardSuit _suit;
    CardPoint _point;
};

#endif // CARD_H
