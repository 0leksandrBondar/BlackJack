#pragma once

#include <memory>
#include <vector>

class PlayerModel;
class AbstractCard;

class AbstractPlayer
{
public:
    AbstractPlayer();
    ~AbstractPlayer();

    int score() const;
    void resetScore();
    void updateScore(int value);

    void clear();

    int balance() const;
    void updateBalance(int value);

    void addCard(std::shared_ptr<AbstractCard> card);
    std::vector<std::shared_ptr<AbstractCard>> cards() const;

    void calculateScore();

private:
    int _balance;
    PlayerModel *_playerModel;
};
