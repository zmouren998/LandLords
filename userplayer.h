#ifndef USERPLAYER_H
#define USERPLAYER_H

#include "player.h"

class UserPlayer : public Player
{
    Q_OBJECT
public:
    // 将构造函数引入子类中
    using Player::Player;
    explicit UserPlayer(QObject *parent = nullptr);

    void prepareCallLord() override;
    void preparePlayHand() override;
};

#endif // USERPLAYER_H
