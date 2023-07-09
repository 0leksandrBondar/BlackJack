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

    void addCard(AbstractCard *card);

    std::vector<AbstractCard *> cards() const;

private:
    int _balance;
    PlayerModel *_playerModel;
};
