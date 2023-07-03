#include "abstractcard.h"

#include "model/cardmodel.h"

#include <Qpainter>
#include <QGraphicsSceneMouseEvent>

AbstractCard::AbstractCard(std::pair<CardSuit, CardValue> carType, QGraphicsItem *parent)
    : QGraphicsItem(parent),
      _cardModel{ std::make_unique<CardModel>(carType.first, carType.second,
                                              QRectF(0, 0, 110, 160)) }
{
    moveBy(2200,-100);
}

QRectF AbstractCard::boundingRect() const
{
    return _cardModel.get()->boundingRect();
}

void AbstractCard::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::red);
    painter->setBrush(Qt::red);
    painter->drawRect(boundingRect());
}
