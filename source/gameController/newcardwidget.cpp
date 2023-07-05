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
        new AbstractCard({ CardSuit::Clubs, CardValue::Two },
                         QStringLiteral(":/whiteCards/clubs_two.png")),
        new AbstractCard({ CardSuit::Clubs, CardValue::Three },
                         QStringLiteral(":/whiteCards/clubs_three.png")),
        new AbstractCard({ CardSuit::Clubs, CardValue::Four },
                         QStringLiteral(":/whiteCards/diamonds_four.png")),
        new AbstractCard({ CardSuit::Clubs, CardValue::Five },
                         QStringLiteral(":/whiteCards/diamonds_five.png")),
        new AbstractCard({ CardSuit::Clubs, CardValue::Six },
                         QStringLiteral(":/whiteCards/diamonds_six.png")),
        new AbstractCard({ CardSuit::Clubs, CardValue::Seven },
                         QStringLiteral(":/whiteCards/diamonds_seven.png")),
        new AbstractCard({ CardSuit::Clubs, CardValue::Eight },
                         QStringLiteral(":/whiteCards/diamonds_eigth.png")),
        new AbstractCard({ CardSuit::Clubs, CardValue::Nine },
                         QStringLiteral(":/whiteCards/diamonds_nine.png")),
        new AbstractCard({ CardSuit::Clubs, CardValue::Ten },
                         QStringLiteral(":/whiteCards/diamonds_ten.png")),
        new AbstractCard({ CardSuit::Clubs, CardValue::Jack },
                         QStringLiteral(":/whiteCards/diamonds_jeck.png")),
        new AbstractCard({ CardSuit::Clubs, CardValue::Queen },
                         QStringLiteral(":/whiteCards/diamonds_queen.png")),
        new AbstractCard({ CardSuit::Clubs, CardValue::King },
                         QStringLiteral(":/whiteCards/diamonds_king.png")),
        new AbstractCard({ CardSuit::Clubs, CardValue::Ace },
                         QStringLiteral(":/whiteCards/diamonds_ace.png")),
        new AbstractCard({ CardSuit::Hearts, CardValue::Two },
                         QStringLiteral(":/whiteCards/diamonds_two.png")),
        new AbstractCard({ CardSuit::Hearts, CardValue::Three },
                         QStringLiteral(":/whiteCards/diamonds_three.png")),
        new AbstractCard({ CardSuit::Hearts, CardValue::Four },
                         QStringLiteral(":/whiteCards/diamonds_four.png")),
        new AbstractCard({ CardSuit::Hearts, CardValue::Five },
                         QStringLiteral(":/whiteCards/diamonds_five.png")),
        new AbstractCard({ CardSuit::Hearts, CardValue::Six },
                         QStringLiteral(":/whiteCards/diamonds_six.png")),
        new AbstractCard({ CardSuit::Hearts, CardValue::Seven },
                         QStringLiteral(":/whiteCards/diamonds_seven.png")),
        new AbstractCard({ CardSuit::Hearts, CardValue::Eight },
                         QStringLiteral(":/whiteCards/diamonds_eight.png")),
        new AbstractCard({ CardSuit::Hearts, CardValue::Nine },
                         QStringLiteral(":/whiteCards/diamonds_nine.png")),
        new AbstractCard({ CardSuit::Hearts, CardValue::Ten },
                         QStringLiteral(":/whiteCards/diamonds_ten.png")),
        new AbstractCard({ CardSuit::Hearts, CardValue::Jack },
                         QStringLiteral(":/whiteCards/diamonds_jeck.png")),
        new AbstractCard({ CardSuit::Hearts, CardValue::Queen },
                         QStringLiteral(":/whiteCards/diamonds_queen.png")),
        new AbstractCard({ CardSuit::Hearts, CardValue::King },
                         QStringLiteral(":/whiteCards/diamonds_king.png")),
        new AbstractCard({ CardSuit::Hearts, CardValue::Ace },
                         QStringLiteral(":/whiteCards/diamonds_ace.png")),
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
        new AbstractCard({ CardSuit::Diamonds, CardValue::Two },
                         QStringLiteral(":/whiteCards/diamonds_two.png")),
        new AbstractCard({ CardSuit::Diamonds, CardValue::Three },
                         QStringLiteral(":/whiteCards/diamonds_three.png")),
        new AbstractCard({ CardSuit::Diamonds, CardValue::Four },
                         QStringLiteral(":/whiteCards/diamonds_four.png")),
        new AbstractCard({ CardSuit::Diamonds, CardValue::Five },
                         QStringLiteral(":/whiteCards/diamonds_five.png")),
        new AbstractCard({ CardSuit::Diamonds, CardValue::Six },
                         QStringLiteral(":/whiteCards/diamonds_six.png")),
        new AbstractCard({ CardSuit::Diamonds, CardValue::Seven },
                         QStringLiteral(":/whiteCards/diamonds_seven.png")),
        new AbstractCard({ CardSuit::Diamonds, CardValue::Eight },
                         QStringLiteral(":/whiteCards/diamonds_eight.png")),
        new AbstractCard({ CardSuit::Diamonds, CardValue::Nine },
                         QStringLiteral(":/whiteCards/diamonds_nine.png")),
        new AbstractCard({ CardSuit::Diamonds, CardValue::Ten },
                         QStringLiteral(":/whiteCards/diamonds_ten.png")),
        new AbstractCard({ CardSuit::Diamonds, CardValue::Jack },
                         QStringLiteral(":/whiteCards/diamonds_jeck.png")),
        new AbstractCard({ CardSuit::Diamonds, CardValue::Queen },
                         QStringLiteral(":/whiteCards/diamonds_queen.png")),
        new AbstractCard({ CardSuit::Diamonds, CardValue::King },
                         QStringLiteral(":/whiteCards/diamonds_king.png")),
        new AbstractCard({ CardSuit::Diamonds, CardValue::Ace },
                         QStringLiteral(":/whiteCards/diamonds_ace.png")),

    };
}

void NewCardWidget::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                          QWidget *widget)
{
    //    painter->setPen(Qt::red);
    //    painter->setBrush(Qt::red);
    //    painter->drawRect(boundingRect());

    // TODO: this code will be using when images for cards will complete

    const QRect rect{ boundingRect().toRect() };
    QPixmap pixmap(":/whiteCards/back.png");

    if (pixmap.isNull())
        return;

    painter->setBrush(pixmap);
    painter->setPen(Qt::black);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawPixmap(rect, pixmap);
}
