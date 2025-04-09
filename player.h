#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>

#include "cards.h"

class Player : public QObject
{
    Q_OBJECT
public:
    // 角色
    enum Role{
        Lord,
        Farmer
    };
    // 性别
    enum Sex{
        Man,
        Woman
    };
    // 头像显示方向
    enum Direction{
        Left,
        Right
    };
    // 玩家类型
    enum Type{
        Robot,
        User
    };

    explicit Player(QObject *parent = nullptr);
    explicit Player(QString name ,QObject* parent = nullptr);

    // 玩家农民还是地主
    void setRole(Role role);
    Role getRole();

    // 玩家性别
    void setSex(Sex sex);
    Sex getSex();
    // 方位
    void setDirection(Direction direction);
    Direction getDirection();
    // 玩家类型
    void setType(Type type);
    Type getType();
    // 玩家分数
    void setScore(int score);
    int getScore();
    // 游戏结果
    void setWin(bool flag);
    bool isWin();

    // 设置当前玩家的前一个玩家和下一个玩家
    void setPrevPlayer(Player* player);
    void setNextPlayer(Player* player);
    Player* getPrevPlayer();
    Player* getNextPlayer();

    // 提供当前对象的上下家
    // 叫地主/抢地主
    void grabLordBet(int point);


    // 存储扑克牌
    void storeDispatchchCard(Card& card);
    // 一次存储多张扑克牌
    void storeDispatchchCard(Cards& cards);

    // 得到所有的牌
    Cards getCards();

    // 清空玩家手中的所有牌
    void clearCards();
    // 出牌(单张/多张)
    void playHand(Cards& cards);

    // 当出牌之后需要知道当前是否为自己出的,或者知道是谁出的
    void setPendingInfo(Player* player,Cards& cards);
    Player* getPendPlayer();
    Cards getPendCards();

    // 抽象出来的方法
    // 有机器人和真人玩家都拥有叫地主和出牌的方法
    virtual void prepareCallLord();
    virtual void preparePlayHand();

signals:

protected:
    int m_score;        // 玩家分数
    QString m_name;     // 玩家姓名
    Role m_role;
    Sex m_sex;
    Direction m_direction;
    Type m_type;
    bool m_isWin;
    Cards m_cards;      // 当前玩家的牌
    Player* m_prev;     // 前一个玩家
    Player* m_next;     // 下一个玩家
    Player* m_pendPlayer;   // 待处理的牌的所有者
    Cards m_pendCard;      // 待处理的牌
};

#endif // PLAYER_H
