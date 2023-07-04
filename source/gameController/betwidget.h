#pragma once

#include <QGraphicsItem>

class BetWidget : public QGraphicsItem
{
public:
    BetWidget(QGraphicsItem *parent = nullptr);

    QRectF boundingRect() const override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};
