#include "newcardwidget.h"

#include "cards/abstractcard.h"
#include "model/cardsuit.h"

#include <Qpainter>
#include <random>

NewCardWidget::NewCardWidget(QGraphicsItem* parent) : QGraphicsItem(parent)
{ /*initCardStack();*/
}

QRectF NewCardWidget::boundingRect() const
{
	return QRectF(0, 0, 110, 150);
}

std::vector<std::shared_ptr<AbstractCard>> NewCardWidget::initCardStack()
{
	using std::make_pair;
	using std::shared_ptr;
	std::vector<shared_ptr<AbstractCard>> cards;

	cards.push_back(
		shared_ptr<AbstractCard>(new AbstractCard(make_pair(CardSuit::Clubs, CardValue::Two), QStringLiteral("clubs_two.png"))));
	cards.push_back(shared_ptr<AbstractCard>(
		new AbstractCard(make_pair(CardSuit::Clubs, CardValue::Three), QStringLiteral("clubs_three.png"))));
	cards.push_back(
		shared_ptr<AbstractCard>(new AbstractCard(make_pair(CardSuit::Clubs, CardValue::Four), QStringLiteral("clubs_four.png"))));
	cards.push_back(
		shared_ptr<AbstractCard>(new AbstractCard(make_pair(CardSuit::Clubs, CardValue::Five), QStringLiteral("clubs_five.png"))));
	cards.push_back(
		shared_ptr<AbstractCard>(new AbstractCard(make_pair(CardSuit::Clubs, CardValue::Six), QStringLiteral("clubs_six.png"))));
	cards.push_back(shared_ptr<AbstractCard>(
		new AbstractCard(make_pair(CardSuit::Clubs, CardValue::Seven), QStringLiteral("clubs_seven.png"))));
	cards.push_back(shared_ptr<AbstractCard>(
		new AbstractCard(make_pair(CardSuit::Clubs, CardValue::Eight), QStringLiteral("clubs_eight.png"))));
	cards.push_back(
		shared_ptr<AbstractCard>(new AbstractCard(make_pair(CardSuit::Clubs, CardValue::Nine), QStringLiteral("clubs_nine.png"))));
	cards.push_back(
		shared_ptr<AbstractCard>(new AbstractCard(make_pair(CardSuit::Clubs, CardValue::Ten), QStringLiteral("clubs_ten.png"))));
	cards.push_back(
		shared_ptr<AbstractCard>(new AbstractCard(make_pair(CardSuit::Clubs, CardValue::Jack), QStringLiteral("clubs_jack.png"))));
	cards.push_back(shared_ptr<AbstractCard>(
		new AbstractCard(make_pair(CardSuit::Clubs, CardValue::Queen), QStringLiteral("clubs_queen.png"))));
	cards.push_back(
		shared_ptr<AbstractCard>(new AbstractCard(make_pair(CardSuit::Clubs, CardValue::King), QStringLiteral("clubs_king.png"))));
	cards.push_back(
		shared_ptr<AbstractCard>(new AbstractCard(make_pair(CardSuit::Clubs, CardValue::Ace), QStringLiteral("clubs_ace.png"))));

	cards.push_back(
		shared_ptr<AbstractCard>(new AbstractCard(make_pair(CardSuit::Hearts, CardValue::Two), QStringLiteral("hearts_two.png"))));
	cards.push_back(shared_ptr<AbstractCard>(
		new AbstractCard(make_pair(CardSuit::Hearts, CardValue::Three), QStringLiteral("hearts_three.png"))));
	cards.push_back(shared_ptr<AbstractCard>(
		new AbstractCard(make_pair(CardSuit::Hearts, CardValue::Four), QStringLiteral("hearts_four.png"))));
	cards.push_back(shared_ptr<AbstractCard>(
		new AbstractCard(make_pair(CardSuit::Hearts, CardValue::Five), QStringLiteral("hearts_five.png"))));
	cards.push_back(
		shared_ptr<AbstractCard>(new AbstractCard(make_pair(CardSuit::Hearts, CardValue::Six), QStringLiteral("hearts_six.png"))));
	cards.push_back(shared_ptr<AbstractCard>(
		new AbstractCard(make_pair(CardSuit::Hearts, CardValue::Seven), QStringLiteral("hearts_seven.png"))));
	cards.push_back(shared_ptr<AbstractCard>(
		new AbstractCard(make_pair(CardSuit::Hearts, CardValue::Eight), QStringLiteral("hearts_eight.png"))));
	cards.push_back(shared_ptr<AbstractCard>(
		new AbstractCard(make_pair(CardSuit::Hearts, CardValue::Nine), QStringLiteral("hearts_nine.png"))));
	cards.push_back(
		shared_ptr<AbstractCard>(new AbstractCard(make_pair(CardSuit::Hearts, CardValue::Ten), QStringLiteral("hearts_ten.png"))));
	cards.push_back(shared_ptr<AbstractCard>(
		new AbstractCard(make_pair(CardSuit::Hearts, CardValue::Jack), QStringLiteral("hearts_jack.png"))));
	cards.push_back(shared_ptr<AbstractCard>(
		new AbstractCard(make_pair(CardSuit::Hearts, CardValue::Queen), QStringLiteral("hearts_queen.png"))));
	cards.push_back(shared_ptr<AbstractCard>(
		new AbstractCard(make_pair(CardSuit::Hearts, CardValue::King), QStringLiteral("hearts_king.png"))));
	cards.push_back(
		shared_ptr<AbstractCard>(new AbstractCard(make_pair(CardSuit::Hearts, CardValue::Ace), QStringLiteral("hearts_ace.png"))));

	cards.push_back(
		shared_ptr<AbstractCard>(new AbstractCard(make_pair(CardSuit::Spades, CardValue::Two), QStringLiteral("spades_two.png"))));
	cards.push_back(shared_ptr<AbstractCard>(
		new AbstractCard(make_pair(CardSuit::Spades, CardValue::Three), QStringLiteral("spades_three.png"))));
	cards.push_back(shared_ptr<AbstractCard>(
		new AbstractCard(make_pair(CardSuit::Spades, CardValue::Four), QStringLiteral("spades_four.png"))));
	cards.push_back(shared_ptr<AbstractCard>(
		new AbstractCard(make_pair(CardSuit::Spades, CardValue::Five), QStringLiteral("spades_five.png"))));
	cards.push_back(
		shared_ptr<AbstractCard>(new AbstractCard(make_pair(CardSuit::Spades, CardValue::Six), QStringLiteral("spades_six.png"))));
	cards.push_back(shared_ptr<AbstractCard>(
		new AbstractCard(make_pair(CardSuit::Spades, CardValue::Seven), QStringLiteral("spades_seven.png"))));
	cards.push_back(shared_ptr<AbstractCard>(
		new AbstractCard(make_pair(CardSuit::Spades, CardValue::Eight), QStringLiteral("spades_eight.png"))));
	cards.push_back(shared_ptr<AbstractCard>(
		new AbstractCard(make_pair(CardSuit::Spades, CardValue::Nine), QStringLiteral("spades_nine.png"))));
	cards.push_back(
		shared_ptr<AbstractCard>(new AbstractCard(make_pair(CardSuit::Spades, CardValue::Ten), QStringLiteral("spades_ten.png"))));
	cards.push_back(shared_ptr<AbstractCard>(
		new AbstractCard(make_pair(CardSuit::Spades, CardValue::Jack), QStringLiteral("spades_jack.png"))));
	cards.push_back(shared_ptr<AbstractCard>(
		new AbstractCard(make_pair(CardSuit::Spades, CardValue::Queen), QStringLiteral("spades_queen.png"))));
	cards.push_back(shared_ptr<AbstractCard>(
		new AbstractCard(make_pair(CardSuit::Spades, CardValue::King), QStringLiteral("spades_king.png"))));
	cards.push_back(
		shared_ptr<AbstractCard>(new AbstractCard(make_pair(CardSuit::Spades, CardValue::Ace), QStringLiteral("spades_ace.png"))));

	cards.push_back(shared_ptr<AbstractCard>(
		new AbstractCard(make_pair(CardSuit::Diamonds, CardValue::Two), QStringLiteral("diamonds_two.png"))));
	cards.push_back(shared_ptr<AbstractCard>(
		new AbstractCard(make_pair(CardSuit::Diamonds, CardValue::Three), QStringLiteral("diamonds_three.png"))));
	cards.push_back(shared_ptr<AbstractCard>(
		new AbstractCard(make_pair(CardSuit::Diamonds, CardValue::Four), QStringLiteral("diamonds_four.png"))));
	cards.push_back(shared_ptr<AbstractCard>(
		new AbstractCard(make_pair(CardSuit::Diamonds, CardValue::Five), QStringLiteral("diamonds_five.png"))));
	cards.push_back(shared_ptr<AbstractCard>(
		new AbstractCard(make_pair(CardSuit::Diamonds, CardValue::Six), QStringLiteral("diamonds_six.png"))));
	cards.push_back(shared_ptr<AbstractCard>(
		new AbstractCard(make_pair(CardSuit::Diamonds, CardValue::Seven), QStringLiteral("diamonds_seven.png"))));
	cards.push_back(shared_ptr<AbstractCard>(
		new AbstractCard(make_pair(CardSuit::Diamonds, CardValue::Eight), QStringLiteral("diamonds_eight.png"))));
	cards.push_back(shared_ptr<AbstractCard>(
		new AbstractCard(make_pair(CardSuit::Diamonds, CardValue::Nine), QStringLiteral("diamonds_nine.png"))));
	cards.push_back(shared_ptr<AbstractCard>(
		new AbstractCard(make_pair(CardSuit::Diamonds, CardValue::Ten), QStringLiteral("diamonds_ten.png"))));
	cards.push_back(shared_ptr<AbstractCard>(
		new AbstractCard(make_pair(CardSuit::Diamonds, CardValue::Jack), QStringLiteral("diamonds_jack.png"))));
	cards.push_back(shared_ptr<AbstractCard>(
		new AbstractCard(make_pair(CardSuit::Diamonds, CardValue::Queen), QStringLiteral("diamonds_queen.png"))));
	cards.push_back(shared_ptr<AbstractCard>(
		new AbstractCard(make_pair(CardSuit::Diamonds, CardValue::King), QStringLiteral("diamonds_king.png"))));
	cards.push_back(shared_ptr<AbstractCard>(
		new AbstractCard(make_pair(CardSuit::Diamonds, CardValue::Ace), QStringLiteral("diamonds_ace.png"))));

	shuffleCards(cards);

	return cards;
}

void NewCardWidget::shuffleCards(std::vector<std::shared_ptr<AbstractCard>>& cards)
{
	std::random_device rd;
	std::mt19937 generator(rd());
	std::shuffle(cards.begin(), cards.end(), generator);
}

void NewCardWidget::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	const QRect rect{boundingRect().toRect()};
	QPixmap pixmap(QStringLiteral(":/whiteCards/back.png"));
	QPixmap pixmap2(QStringLiteral(":/darkCards/back.png"));

	if (pixmap.isNull())
	{
		return;
	}

	painter->setBrush(pixmap);
	painter->setPen(Qt::black);
	painter->setRenderHint(QPainter::Antialiasing);
	painter->drawPixmap(rect, pixmap);
}
