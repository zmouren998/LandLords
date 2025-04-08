#include "card.h"

Card::Card()
{

}

void Card::setCardSuit(CardPoint suit){
    this->_suit = suit;
}
void Card::setCardPoint(CardPoint point){
    this->_point = point;
}
CardSuit Card::suit(){
    return _suit;
}
CardPoint Card::point(){
    return _point;
}
