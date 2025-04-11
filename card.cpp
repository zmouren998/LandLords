#include "card.h"

Card::Card()
{

}

Card::Card(CardPoint point, CardSuit suit)
{
    _point = point;
    _suit = suit;
}

void Card::setCardSuit(CardSuit suit){
    _suit = suit;
}
void Card::setCardPoint(CardPoint point){
    this->_point = point;
}
Card::CardSuit Card::suit() const {
    return _suit;
}
Card::CardPoint Card::point() const {
    return _point;
}

