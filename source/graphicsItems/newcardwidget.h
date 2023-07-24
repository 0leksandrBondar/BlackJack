#pragma once

#include <QGraphicsItem>

#include <memory>

class AbstractCard;

class NewCardWidget : public QGraphicsItem
{
public:
    NewCardWidget(QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const override;

    std::vector<std::shared_ptr<AbstractCard>> initCardStack();

private:
    void shuffleCards(std::vector<std::shared_ptr<AbstractCard>> &cards);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};
