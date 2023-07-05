#include "betwidget.h"

#include <Qpainter>

BetWidget::BetWidget(QGraphicsItem *parent) : QGraphicsItem(parent) {}

QRectF BetWidget::boundingRect() const { return QRectF(0, 0, 100, 100); }

void BetWidget::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    const QRect rect{ boundingRect().toRect() };
    QPixmap pixmap(":/dib.png");

    if (pixmap.isNull())
        return;

    painter->setBrush(pixmap);
    painter->setPen(Qt::black);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawPixmap(rect, pixmap);
}
