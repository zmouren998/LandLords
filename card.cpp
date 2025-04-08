#include "card.h"

Card::Card()
{

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

