#include "abstractplayer.h"

#include "model/playermodel.h"

#include <memory>

AbstractPlayer::AbstractPlayer() : _playerModel{ new PlayerModel() } {}

AbstractPlayer::~AbstractPlayer() { delete _playerModel; }

int AbstractPlayer::score() const { return _playerModel->score(); }

void AbstractPlayer::resetScore() { _playerModel->resetScore(); }

void AbstractPlayer::clear() { _playerModel->clear(); }

int AbstractPlayer::balance() const { return _playerModel->balance(); }

void AbstractPlayer::updateBalance(int value) { _playerModel->updateBalance(value); }

void AbstractPlayer::addCard(AbstractCard *card) { _playerModel->addCard(card); }

std::vector<AbstractCard *> AbstractPlayer::cards() const { return _playerModel->cards(); }

void AbstractPlayer::calculateScore() { _playerModel->calculateScore(); }
