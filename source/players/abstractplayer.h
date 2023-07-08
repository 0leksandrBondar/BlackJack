#pragma once

#include "model/cardsuit.h"

#include <QVector>

class PlayerModel;
class AbstractCard;

class AbstractPlayer
{
public:
    AbstractPlayer();
    ~AbstractPlayer();

    int score() const;
    void updateScore(int value);

    int balance() const;
    void updateBalance(int value);

    void addCard(CardValue cardValue);

private:
    int _balance;
    PlayerModel *_playerModel;
   // QVector<std::shared_ptr<AbstractCard>> _cards;
};
