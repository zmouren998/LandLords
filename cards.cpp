#include "cards.h"

Cards::Cards()
{

}

void Cards::add(const Card &card)
{
    m_cards.insert(card);
}

void Cards::add(const Cards &cards)
{
    // 交集将 cards 中的m_cards都添加到当前类的m_cards;
    m_cards.unite(cards.m_cards);
}

void Cards::remove(const Card &card)
{
    m_cards.remove(card);
}

void Cards::remove(const Cards &cards)
{
    // 将cards中从当前的删除
    m_cards.subtract(cards.m_cards);
}

Cards &Cards::operator<<(const Card &other)
{
    add(other);
    return *this;
}

int Cards::CardsNum()
{
    return m_cards.count();
}

bool Cards::CardsIsEmpty()
{
    return m_cards.isEmpty();
}

void Cards::ClearCards()
{
    m_cards.clear();
}

Cards& Cards::operator<<(const Cards& other)
{
    add(other);
    return *this;
}

Card::CardPoint Cards::maxPoint()
{
    Card::CardPoint maxPoint = Card::Card_Begin;
    if(!m_cards.isEmpty()){
        for(QSet<Card>::iterator it = m_cards.begin();it != m_cards.end();++it){
            if(it->point() > maxPoint){
                maxPoint = it->point();
            }
        }
    }
    return maxPoint;
}

Card::CardPoint Cards::minPoint()
{
    Card::CardPoint minPoint = Card::Card_End;
    if(!m_cards.isEmpty()){
        for(QSet<Card>::iterator it = m_cards.begin();it != m_cards.end();++it){
            if(it->point() < minPoint){
                minPoint = it->point();
            }
        }
    }
    return minPoint;
}

int Cards::pointCount(Card::CardPoint point)
{
    int count = 0;
    if(!m_cards.isEmpty()){
        for(QSet<Card>::iterator it = m_cards.begin();it != m_cards.end();++it){
            if(it->point() < point){
                count++;
            }
        }
    }
    return count;
}

bool Cards::contains(const Card &card)
{
    return m_cards.contains(card);
}

bool Cards::contains(const Cards& cards)
{
    return m_cards.contains(cards.m_cards);
}
#include <QRandomGenerator>
Card Cards::takeRandCard()
{
    int num = QRandomGenerator::global()->bounded(m_cards.count());
    QSet<Card>::const_iterator it = m_cards.cbegin();
    for(int i = 0;i <num;++i,++it);
    Card tmp = *it;
    // 将发出的牌删除
    m_cards.erase(it);
    return tmp;
}

CardList Cards::toCardList(SortType type)
{
    CardList list;
    for(auto i = m_cards.begin();i != m_cards.end();++i){
        list << *i;
    }
    if(type == Asc){
        std::sort(list.begin(),list.end(),[](const Card& a,const Card& b)-> bool{
            if(a.point() == b.point()){
                return a.suit() < b.suit();
            }
            else{
                return a.point() < b.point();
            }
        });
    }else if(type == Desc){
        std::sort(list.begin(),list.end(),[](const Card& a,const Card& b)-> bool{
            if(a.point() == b.point()){
                return a.suit() > b.suit();
            }
            else{
                return a.point() > b.point();
            }
        });
    }
    return list;
}
