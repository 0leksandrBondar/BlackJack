#pragma once

#include <QGraphicsItem>

#include <memory>

class AbstractCard;

class NewCardWidget : public QGraphicsItem
{
public:
    NewCardWidget(QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const override;

   std::vector<AbstractCard *> initCardStack();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};
