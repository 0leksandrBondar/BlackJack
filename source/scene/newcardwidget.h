#pragma once

#include <QGraphicsItem>

class NewCardWidget : public QGraphicsItem
{
public:
    NewCardWidget(QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};
