#include "abstractplayer.h"

AbstractPlayer::AbstractPlayer() {}

int AbstractPlayer::score() const { return _score; }

int AbstractPlayer::balance() const { return _balance; }

void AbstractPlayer::updateBalance(int value) { _balance += value; }

void AbstractPlayer::updateScore(int value) { _score += value; }

void AbstractPlayer::addCard(AbstractCard *newCard) { _cards.push_back(newCard); }
