#include "newcardwidget.h"

#include "cards/abstractcard.h"
#include "model/cardsuit.h"
#include <memory>
#include <random>

#include <Qpainter>

NewCardWidget::NewCardWidget(QGraphicsItem *parent) : QGraphicsItem(parent) { initCardStack(); }

QRectF NewCardWidget::boundingRect() const { return QRectF(0, 0, 110, 150); }

std::vector<AbstractCard *> NewCardWidget::initCardStack()
{
    std::vector<AbstractCard *> cards;
    using namespace std;

    cards.push_back(new AbstractCard(make_pair(CardSuit::Clubs, CardValue::Two),
                                     QStringLiteral(":/whiteCards/clubs_two.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Clubs, CardValue::Three),
                                     QStringLiteral(":/whiteCards/clubs_three.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Clubs, CardValue::Four),
                                     QStringLiteral(":/whiteCards/clubs_four.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Clubs, CardValue::Five),
                                     QStringLiteral(":/whiteCards/clubs_five.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Clubs, CardValue::Six),
                                     QStringLiteral(":/whiteCards/clubs_six.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Clubs, CardValue::Seven),
                                     QStringLiteral(":/whiteCards/clubs_seven.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Clubs, CardValue::Eight),
                                     QStringLiteral(":/whiteCards/clubs_eigth.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Clubs, CardValue::Nine),
                                     QStringLiteral(":/whiteCards/clubs_nine.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Clubs, CardValue::Ten),
                                     QStringLiteral(":/whiteCards/clubs_ten.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Clubs, CardValue::Jack),
                                     QStringLiteral(":/whiteCards/clubs_jeck.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Clubs, CardValue::Queen),
                                     QStringLiteral(":/whiteCards/clubs_queen.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Clubs, CardValue::King),
                                     QStringLiteral(":/whiteCards/clubs_king.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Clubs, CardValue::Ace),
                                     QStringLiteral(":/whiteCards/clubs_ace.png")));

    cards.push_back(new AbstractCard(make_pair(CardSuit::Hearts, CardValue::Two),
                                     QStringLiteral(":/whiteCards/hearts_two.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Hearts, CardValue::Three),
                                     QStringLiteral(":/whiteCards/hearts_three.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Hearts, CardValue::Four),
                                     QStringLiteral(":/whiteCards/hearts_four.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Hearts, CardValue::Five),
                                     QStringLiteral(":/whiteCards/hearts_five.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Hearts, CardValue::Six),
                                     QStringLiteral(":/whiteCards/hearts_six.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Hearts, CardValue::Seven),
                                     QStringLiteral(":/whiteCards/hearts_seven.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Hearts, CardValue::Eight),
                                     QStringLiteral(":/whiteCards/hearts_eight.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Hearts, CardValue::Nine),
                                     QStringLiteral(":/whiteCards/hearts_nine.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Hearts, CardValue::Ten),
                                     QStringLiteral(":/whiteCards/hearts_ten.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Hearts, CardValue::Jack),
                                     QStringLiteral(":/whiteCards/hearts_jeck.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Hearts, CardValue::Queen),
                                     QStringLiteral(":/whiteCards/hearts_queen.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Hearts, CardValue::King),
                                     QStringLiteral(":/whiteCards/hearts_king.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Hearts, CardValue::Ace),
                                     QStringLiteral(":/whiteCards/hearts_ace.png")));

    cards.push_back(new AbstractCard(make_pair(CardSuit::Spades, CardValue::Two),
                                     QStringLiteral(":/whiteCards/spades_two.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Spades, CardValue::Three),
                                     QStringLiteral(":/whiteCards/spades_three.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Spades, CardValue::Four),
                                     QStringLiteral(":/whiteCards/spades_four.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Spades, CardValue::Five),
                                     QStringLiteral(":/whiteCards/spades_five.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Spades, CardValue::Six),
                                     QStringLiteral(":/whiteCards/spades_six.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Spades, CardValue::Seven),
                                     QStringLiteral(":/whiteCards/spades_seven.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Spades, CardValue::Eight),
                                     QStringLiteral(":/whiteCards/spades_eight.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Spades, CardValue::Nine),
                                     QStringLiteral(":/whiteCards/spades_nine.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Spades, CardValue::Ten),
                                     QStringLiteral(":/whiteCards/spades_ten.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Spades, CardValue::Jack),
                                     QStringLiteral(":/whiteCards/spades_jeck.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Spades, CardValue::Queen),
                                     QStringLiteral(":/whiteCards/spades_queen.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Spades, CardValue::King),
                                     QStringLiteral(":/whiteCards/spades_king.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Spades, CardValue::Ace),
                                     QStringLiteral(":/whiteCards/spades_ace.png")));

    cards.push_back(new AbstractCard(make_pair(CardSuit::Diamonds, CardValue::Two),
                                     QStringLiteral(":/whiteCards/diamonds_two.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Diamonds, CardValue::Three),
                                     QStringLiteral(":/whiteCards/diamonds_three.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Diamonds, CardValue::Four),
                                     QStringLiteral(":/whiteCards/diamonds_four.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Diamonds, CardValue::Five),
                                     QStringLiteral(":/whiteCards/diamonds_five.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Diamonds, CardValue::Six),
                                     QStringLiteral(":/whiteCards/diamonds_six.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Diamonds, CardValue::Seven),
                                     QStringLiteral(":/whiteCards/diamonds_seven.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Diamonds, CardValue::Eight),
                                     QStringLiteral(":/whiteCards/diamonds_eight.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Diamonds, CardValue::Nine),
                                     QStringLiteral(":/whiteCards/diamonds_nine.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Diamonds, CardValue::Ten),
                                     QStringLiteral(":/whiteCards/diamonds_ten.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Diamonds, CardValue::Jack),
                                     QStringLiteral(":/whiteCards/diamonds_jeck.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Diamonds, CardValue::Queen),
                                     QStringLiteral(":/whiteCards/diamonds_queen.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Diamonds, CardValue::King),
                                     QStringLiteral(":/whiteCards/diamonds_king.png")));
    cards.push_back(new AbstractCard(make_pair(CardSuit::Diamonds, CardValue::Ace),
                                     QStringLiteral(":/whiteCards/diamonds_ace.png")));

    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(cards.begin(), cards.end(), generator);

    return cards;
}

void NewCardWidget::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                          QWidget *widget)
{
    const QRect rect{ boundingRect().toRect() };
    QPixmap pixmap(QStringLiteral(":/whiteCards/back.png"));

    if (pixmap.isNull())
        return;

    painter->setBrush(pixmap);
    painter->setPen(Qt::black);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawPixmap(rect, pixmap);
}
