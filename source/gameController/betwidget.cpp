#include "betwidget.h"

#include <Qpainter>

BetWidget::BetWidget(QGraphicsItem *parent):  QGraphicsItem(parent)
{

}

QRectF BetWidget::boundingRect() const
{
    return QRectF(0,0,100,100);
}

void BetWidget::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::blue);
    painter->setBrush(Qt::blue);
    painter->drawEllipse(boundingRect());
}
