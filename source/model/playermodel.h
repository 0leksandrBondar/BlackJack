#pragma once

#include "cards/abstractcard.h"
#include <vector>

class PlayerModel
{
public:
    PlayerModel();

    int score() const;
    void resetScore();

    void addCard(AbstractCard *cardValue);
    std::vector<AbstractCard *> cards() const;
    void calculateScore();

    void clear();

private:
    int _score{ 0 };
    std::vector<AbstractCard *> _cards;
};
