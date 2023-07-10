#pragma once

#include <QVector>

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

    void addCard(AbstractCard *card);
    std::vector<AbstractCard *> cards() const;

    void calculateScore();

private:
    int _balance;
    PlayerModel *_playerModel;
};
