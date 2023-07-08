#include "label.h"
#include <QColor>
#include <QFont>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

Label::Label(QString text, QGraphicsItem *parent) : QGraphicsTextItem(parent) , _textLabel(text)
{
    updateScoreOnlabel(0);
    QFont font;
    font.setPointSize(12);
    setFont(font);
    setDefaultTextColor(Qt::yellow);
}

void Label::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setRenderHint(QPainter::TextAntialiasing, true);

    QRectF rect = boundingRect();

    QColor backgroundColor(Qt::black);
    painter->setBrush(backgroundColor);
    painter->setPen(Qt::black);
    painter->drawRect(rect);

    QGraphicsTextItem::paint(painter, option, widget);
}

QRectF Label::boundingRect() const
{
    return QGraphicsTextItem::boundingRect();
}

void Label::updateScoreOnlabel(int value)
{
    _score += value;
    setPlainText(_textLabel + QString::number(_score));
}
