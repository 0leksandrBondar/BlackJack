#include "newcardwidget.h"

#include <Qpainter>

NewCardWidget::NewCardWidget(QGraphicsItem *parent) : QGraphicsItem(parent)
{
}

QRectF NewCardWidget::boundingRect() const
{
    return QRectF(0, 0, 110, 150);
}

void NewCardWidget::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::gray);
    painter->setBrush(Qt::gray);
    painter->drawRect(boundingRect());
}
