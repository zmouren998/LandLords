#include "player.h"

Player::Player(QObject *parent) : QObject(parent)
{

}

Player::Player(QString name, QObject *parent):QObject(parent),m_name(name)
{

}

void Player::setRole(Role role)
{
    m_role = role;
}

Player::Role Player::getRole()
{
    return m_role;
}

void Player::setSex(Sex sex)
{
    m_sex = sex;
}

Player::Sex Player::getSex()
{
    return m_sex;
}

void Player::setDirection(Direction direction)
{
    m_direction = direction;
}

Player::Direction Player::getDirection()
{
    return m_direction;
}

void Player::setType(Type type)
{
    m_type = type;
}

Player::Type Player::getType()
{
    return m_type;
}

void Player::setScore(int score)
{
    m_score = score;
}

int Player::getScore()
{
    return m_score;
}

void Player::setWin(bool flag)
{
    m_isWin = flag;
}

bool Player::isWin()
{
    return m_isWin;
}

void Player::setPrevPlayer(Player *player)
{
    m_prev = player;
}

void Player::setNextPlayer(Player *player)
{
    m_next = player;
}

Player *Player::getPrevPlayer()
{
    return m_prev;
}

Player *Player::getNextPlayer()
{
    return m_next;
}

void Player::grabLordBet(int point)
{
    // TODO 待完成
}

void Player::storeDispatchchCard(Card &card)
{
    m_cards.add(card);
}

void Player::storeDispatchchCard(Cards &cards)
{
    m_cards.add(cards);
}

Cards Player::getCards()
{
    return m_cards;
}

void Player::clearCards()
{
    m_cards.ClearCards();
}

void Player::playHand(Cards &cards)
{
    m_cards.remove(cards);
}

void Player::setPendingInfo(Player *player, Cards &cards)
{
    m_pendPlayer = player;
    m_pendCard = cards;
}

Player *Player::getPendPlayer()
{
    return m_pendPlayer;
}

Cards Player::getPendCards()
{
    return m_pendCard;
}

void Player::prepareCallLord(){}

void Player::preparePlayHand(){}

