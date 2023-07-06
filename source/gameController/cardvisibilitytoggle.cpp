#include "cardvisibilitytoggle.h"

#include <QPainter>

CardVisibilityToggle::CardVisibilityToggle(QGraphicsItem *parent) : QGraphicsItem(parent) {}

QRectF CardVisibilityToggle::boundingRect() const { return QRectF(0, 0, 110, 160); }

void CardVisibilityToggle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                                 QWidget *widget)
{
    QColor blockColor = Qt::black;
    QColor textColor = Qt::green;

    QRectF blockRect = boundingRect();

    painter->setPen(Qt::NoPen);
    painter->setBrush(blockColor);
    painter->drawRect(blockRect);

    QFont font;
    font.setPixelSize(16);
    painter->setFont(font);

    painter->setPen(textColor);
    painter->drawText(blockRect, Qt::AlignCenter, "hide/show");
}
