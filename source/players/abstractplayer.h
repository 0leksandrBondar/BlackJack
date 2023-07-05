#pragma once

#include <QVector>

class AbstractCard;

class AbstractPlayer
{
public:
    AbstractPlayer();

    int score() const;
    void updateScore(int value);

    int balance() const;
    void updateBalance(int value);

    void addCard(AbstractCard *newCard);

private:
    int _score;
    int _balance;
    QVector<AbstractCard *> _cards;
};
