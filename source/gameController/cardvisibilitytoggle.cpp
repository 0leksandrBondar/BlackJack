#include "cardvisibilitytoggle.h"

#include <QPainter>

CardVisibilityToggle::CardVisibilityToggle(QGraphicsItem *parent) : QGraphicsItem(parent) {}

QRectF CardVisibilityToggle::boundingRect() const { return QRectF(0, 0, 110, 160); }

void CardVisibilityToggle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                                 QWidget *widget)
{
    painter->setPen(Qt::blue);
    painter->setBrush(Qt::blue);
    painter->drawRect(boundingRect());
}
