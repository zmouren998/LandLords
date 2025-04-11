#include "gamecontrol.h"

#include <QRandomGenerator>

GameControl::GameControl(QObject *parent) : QObject(parent)
{

}

void GameControl::playerInit()
{
    m_robotLeft = new Robot("机器人A",this);
    m_robotRight = new Robot("机器人B",this);
    m_user = new UserPlayer("我自己",this);

    // 头像显示
    m_robotLeft->setDirection(Player::Left);
    m_robotRight->setDirection(Player::Right);
    m_user->setDirection(Player::Right);

    // 性别
    Player::Sex sex;
    // 随机数 0 或 1
    sex = (Player::Sex)QRandomGenerator::global()->bounded(2);
    m_robotLeft->setSex(sex);
    sex = (Player::Sex)QRandomGenerator::global()->bounded(2);
    m_robotRight->setSex(sex);
    sex = (Player::Sex)QRandomGenerator::global()->bounded(2);
    m_user->setSex(sex);

    // 设置每个玩家的前一个玩家和下一个玩家
    m_robotRight->setPrevPlayer(m_user);
    m_robotRight->setNextPlayer(m_robotLeft);

    m_robotLeft->setPrevPlayer(m_robotRight);
    m_robotLeft->setNextPlayer(m_user);

    m_user->setPrevPlayer(m_robotLeft);
    m_user->setNextPlayer(m_robotRight);

    // 指定当前玩家就是真人玩家
    m_currPlayer = m_user;
}

Robot *GameControl::getLeftRobot()
{
    return m_robotLeft;
}

Robot *GameControl::getRightRobot()
{
    return m_robotRight;
}

UserPlayer *GameControl::getUserPlayer()
{
    return m_user;
}

void GameControl::setCurrentPlayer(Player *player)
{
    m_currPlayer = player;
}

Player *GameControl::getCurrentPlayer()
{
    return m_currPlayer;
}

Player *GameControl::getPendPlayer()
{
    return m_pendPlayer;
}

Cards GameControl::getPendCards()
{
    return m_pendCards;
}

void GameControl::initAllCards()
{
    m_allCards.ClearCards();
    // 将所有的牌添加到集合中
    for(Card::CardPoint p = static_cast<Card::CardPoint>(Card::Card_Begin + 1);p < Card::Card_End;static_cast<Card::CardPoint>(p + 1)){
        for(Card::CardSuit s = static_cast<Card::CardSuit>(Card::Suit_Begin + 1);s < Card::Suit_End;static_cast<Card::CardPoint>(s + 1)){
            // 初始化一张牌
            Card c(p,s);
            m_allCards.add(c);
        }
    }
    // 将大王小王添加到牌库
    m_allCards.add((Card(Card::Card_BJ,Card::Suit_Begin)));
    m_allCards.add((Card(Card::Card_SJ,Card::Suit_Begin)));
}

Card GameControl::takeOneCard()
{
    return m_allCards.takeRandCard();
}

Cards GameControl::getSurplusCards()
{
    // 将剩下的牌全部发出
    return m_allCards;
}

void GameControl::resetCardData()
{
    initAllCards();

    // 清空所有玩家的牌
    m_robotLeft->clearCards();
    m_robotRight->clearCards();
    m_user->clearCards();

    // 重置
    m_pendCards.ClearCards();
    m_pendPlayer = nullptr;
}

void GameControl::startLordCard()
{
    // 当前的玩家有抽象的方法叫地主
    m_currPlayer->prepareCallLord();
}

void GameControl::becomeLord(Player *player)
{
    player->setRole(Player::Lord);
    player->getPrevPlayer()->setRole(Player::Farmer);
    player->getNextPlayer()->setRole(Player::Farmer);

    // 当前的用户要更改
    m_currPlayer = player;
    // 获取地主牌
    player->storeDispatchchCard(m_allCards);
    m_currPlayer->preparePlayHand();        // 开始出牌
}

void GameControl::clearPlayerScore()
{
    // 清空三个玩家的分数
    m_robotLeft->setScore(0);
    m_robotRight->setScore(0);
    m_user->setScore(0);
}
