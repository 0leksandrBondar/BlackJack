#include "abstractcard.h"

#include "model/cardmodel.h"

#include <Qpainter>
#include <QGraphicsSceneMouseEvent>
#include <QPixmap>

AbstractCard::AbstractCard(std::pair<CardSuit, CardValue> carType, QGraphicsItem *parent)
    : QGraphicsItem(parent),
      _cardModel{ std::make_unique<CardModel>(carType.first, carType.second,
                                              QRectF(0, 0, 110, 160)) }
{
}

QRectF AbstractCard::boundingRect() const
{
    return _cardModel.get()->boundingRect();
}

void AbstractCard::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    const QRect rect{ boundingRect().toRect() };
    QPixmap pixmap(":/2.jpg");

    if (pixmap.isNull())
        return;

    painter->setBrush(pixmap);
    painter->setPen(Qt::black);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawPixmap(rect, pixmap);
}
