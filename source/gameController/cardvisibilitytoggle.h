#pragma once

#include <QGraphicsItem>

class CardVisibilityToggle : public QGraphicsItem
{
public:
    CardVisibilityToggle(QGraphicsItem *parent = nullptr);

    QRectF boundingRect() const override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};
