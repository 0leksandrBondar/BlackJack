#pragma once

#include <QGraphicsItem>
#include <QPixmap>

#include <functional>

class CircleWidget : public QGraphicsItem
{
    using Callback = std::function<void()>;

public:
    CircleWidget(std::string pathToImage, QGraphicsItem *parent = nullptr);

    QRectF boundingRect() const override;

    void onClick(Callback func);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    const QPixmap _pixmap;
    Callback _callback;
};
