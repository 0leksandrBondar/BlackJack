#include "cardmodel.h"

CardModel::CardModel(CardSuit cardSuit, CardValue cardValue, QRectF rect)
    : _boundingRect{ rect }, _cardSuit{ cardSuit }, _cardValue{ cardValue }
{
}

int CardModel::value() const { return _value; }

int CardModel::cardValue() const { return _value; }

QRectF CardModel::boundingRect() const { return _boundingRect; }

std::pair<CardSuit, CardValue> CardModel::card() const { return { _cardSuit, _cardValue }; }
