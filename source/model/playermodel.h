#pragma once

#include "cards/abstractcard.h"
#include <vector>

class PlayerModel
{
public:
    PlayerModel();

    int score() const;
    void resetScore();

    int balance() const;
    void updateBalance(int value);

    void addCard(AbstractCard *cardValue);
    std::vector<AbstractCard *> cards() const;
    void calculateScore();

    void clear();

private:
    int _score{ 0 };
    int _balance{ 25 };
    std::vector<AbstractCard *> _cards;
};
