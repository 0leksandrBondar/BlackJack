#pragma once

#include <QGraphicsTextItem>

class Label : public QGraphicsTextItem
{
public:
    Label(QString text = "", QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const override;

    void updateScoreOnlabel(int value);

private:
    QString _textLabel;
    int _score{ 0 };

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};
