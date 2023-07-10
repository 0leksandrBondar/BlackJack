#include "circlewidget.h"

#include <Qpainter>

CircleWidget::CircleWidget(std::string pathToImage, QGraphicsItem *parent)
    : QGraphicsItem(parent), _pixmap{ QString::fromStdString(pathToImage) }, _callback{ []() {} }
{
}

QRectF CircleWidget::boundingRect() const { return QRectF(0, 0, 100, 100); }

void CircleWidget::onClick(Callback func) { _callback = func; }

void CircleWidget::mousePressEvent(QGraphicsSceneMouseEvent *event) { _callback(); }

void CircleWidget::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    const QRect rect{ boundingRect().toRect() };

    painter->setBrush(_pixmap);
    painter->setPen(Qt::black);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawPixmap(rect, _pixmap);
}
