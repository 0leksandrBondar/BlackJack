#pragma once

#include "cardsuit.h"

#include <QRectF>

class CardModel
{
public:
    CardModel(CardSuit cardSuit, CardValue cardValue, QRectF rect);

    int value() const;
    int cardValue() const;
    QRectF boundingRect() const;
    std::pair<CardSuit, CardValue> card() const;

private:
    int _value;
    QRectF _boundingRect;
    CardSuit _cardSuit{ CardSuit::Undefined };
    CardValue _cardValue{ CardValue::Undefined };
};
