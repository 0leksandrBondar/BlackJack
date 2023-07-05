#include "newcardwidget.h"

#include "cards/abstractcard.h"
#include "model/cardsuit.h"

#include <Qpainter>

NewCardWidget::NewCardWidget(QGraphicsItem *parent) : QGraphicsItem(parent) { initCardStack(); }

QRectF NewCardWidget::boundingRect() const { return QRectF(0, 0, 110, 150); }

AbstractCard *NewCardWidget::getNewCard() const { return _cardStack[rand() % _cardStack.size()]; }

void NewCardWidget::initCardStack()
{
    _cardStack = {
        new AbstractCard({ CardSuit::Clubs, CardValue::Two }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Clubs, CardValue::Three }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Clubs, CardValue::Four }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Clubs, CardValue::Five }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Clubs, CardValue::Six }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Clubs, CardValue::Seven }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Clubs, CardValue::Eight }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Clubs, CardValue::Nine }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Clubs, CardValue::Ten }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Clubs, CardValue::Jack }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Clubs, CardValue::Queen }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Clubs, CardValue::King }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Clubs, CardValue::Ace }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Hearts, CardValue::Two }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Hearts, CardValue::Three }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Hearts, CardValue::Four }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Hearts, CardValue::Five }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Hearts, CardValue::Six }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Hearts, CardValue::Seven }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Hearts, CardValue::Eight }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Hearts, CardValue::Nine }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Hearts, CardValue::Ten }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Hearts, CardValue::Jack }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Hearts, CardValue::Queen }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Hearts, CardValue::King }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Hearts, CardValue::Ace }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Spades, CardValue::Two }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Spades, CardValue::Three }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Spades, CardValue::Four }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Spades, CardValue::Five }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Spades, CardValue::Six }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Spades, CardValue::Seven }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Spades, CardValue::Eight }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Spades, CardValue::Nine }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Spades, CardValue::Ten }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Spades, CardValue::Jack }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Spades, CardValue::Queen }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Spades, CardValue::King }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Spades, CardValue::Ace }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Diamonds, CardValue::Two }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Diamonds, CardValue::Three }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Diamonds, CardValue::Four }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Diamonds, CardValue::Five }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Diamonds, CardValue::Six }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Diamonds, CardValue::Seven }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Diamonds, CardValue::Eight }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Diamonds, CardValue::Nine }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Diamonds, CardValue::Ten }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Diamonds, CardValue::Jack }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Diamonds, CardValue::Queen }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Diamonds, CardValue::King }, ":/2.jpg"),
        new AbstractCard({ CardSuit::Diamonds, CardValue::Ace }, ":/2.jpg"),

    };
}

void NewCardWidget::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                          QWidget *widget)
{
    painter->setPen(Qt::red);
    painter->setBrush(Qt::red);
    painter->drawRect(boundingRect());

    // TODO: this code will be using when images for cards will complete

    //    const QRect rect{ boundingRect().toRect() };
    //    QPixmap pixmap(":/stack.png");

    //    if (pixmap.isNull())
    //        return;

    //    painter->setBrush(pixmap);
    //    painter->setPen(Qt::black);
    //    painter->setRenderHint(QPainter::Antialiasing);
    //    painter->drawPixmap(rect, pixmap);
}
