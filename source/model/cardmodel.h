#pragma once

#include "cardsuit.h"

#include <QRectF>

class CardModel
{
public:
    CardModel(CardSuit cardSuit, CardValue cardValue, QRectF rect);

    int value() const;
    QPointF pos() const;
    int cardValue() const;
    QRectF boundingRect() const;
    std::pair<CardSuit, CardValue> card() const;

    void setCardVisible(bool visible);
    bool cardVisible() const;

private:
    int _value;
    bool _cardVisible{ true };
    QRectF _boundingRect;
    const QPointF _pos{ 500, 475 };
    CardSuit _cardSuit{ CardSuit::Undefined };
    CardValue _cardValue{ CardValue::Undefined };
};
