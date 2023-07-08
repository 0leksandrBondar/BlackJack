#pragma once

#include "model/cardsuit.h"
#include <vector>

class PlayerModel
{
public:
    PlayerModel();

    int score() const;
    void addCard(CardValue cardValue);

    void calculateScore();

private:
    int _score{ 0 };
    std::vector<CardValue> _cardValues;
};
