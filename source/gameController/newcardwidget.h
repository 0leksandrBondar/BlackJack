#pragma once

#include <QGraphicsItem>

class AbstractCard;

class NewCardWidget : public QGraphicsItem
{
public:
    NewCardWidget(QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const override;

    AbstractCard *getNewCard() const;

private:
    void initCardStack();
    QVector<AbstractCard *> _cardStack;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};
