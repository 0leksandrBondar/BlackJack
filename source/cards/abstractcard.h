#pragma once

#include <QGraphicsItem>

#include <memory>

class CardModel;
enum class CardSuit;
enum class CardValue;

class AbstractCard : public QGraphicsItem
{
public:
    AbstractCard(std::pair<CardSuit, CardValue> carType, QString path,
                 QGraphicsItem *parent = nullptr);

    QRectF boundingRect() const override;

    std::pair<CardSuit, CardValue> cardType() const;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QString _pathImage;
    std::unique_ptr<CardModel> _cardModel;
};
