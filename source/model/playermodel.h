#pragma once

#include "cards/abstractcard.h"

#include <memory>
#include <vector>

class PlayerModel
{
public:
    PlayerModel();

    int score() const;
    void resetScore();

    int balance() const;
    void updateBalance(int value);

    void addCard(std::shared_ptr<AbstractCard> cardValue);
    std::vector<std::shared_ptr<AbstractCard>> cards() const;
    void calculateScore();

    void clear();

private:
    int _score{ 0 };
    int _balance{ 25 };
    std::vector<std::shared_ptr<AbstractCard>> _cards;
};
