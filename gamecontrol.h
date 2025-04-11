#ifndef GAMECONTROL_H
#define GAMECONTROL_H

#include <QObject>

#include <robot.h>          // 机器人玩家
#include "userplayer.h"     // 真人玩家

// 游戏控制类
class GameControl : public QObject
{
    Q_OBJECT
public:
    explicit GameControl(QObject *parent = nullptr);

    // 初始化玩家
    void playerInit();

    // 得到玩家的实例对象
    Robot *getLeftRobot();
    Robot* getRightRobot();
    UserPlayer* getUserPlayer();

    void setCurrentPlayer(Player* player);
    Player* getCurrentPlayer();

    // 得到出牌玩家和打出的牌
    Player* getPendPlayer();
    Cards getPendCards();

    // 初始化扑克牌
    void initAllCards();

    // 每次发一张牌
    Card takeOneCard();
    // 得到最后的三张牌
    Cards getSurplusCards();
    // 重置卡牌数据
    void resetCardData();

    // 准备叫地主
    void startLordCard();
    // 成为地主
    void becomeLord(Player* player);

    // 清空玩家的分数
    void clearPlayerScore();

signals:


private:
    Robot* m_robotLeft;     // 左边机器人玩家
    Robot* m_robotRight;    // 右边机器人玩家
    UserPlayer* m_user;     // 真人玩家
    Player* m_currPlayer;   // 当前行动的玩家
    Player* m_pendPlayer;   // 待处理的牌的所属玩家
    Cards m_pendCards;      // 待处理的牌
    Cards m_allCards;       // 所有的牌集合
};

#endif // GAMECONTROL_H
