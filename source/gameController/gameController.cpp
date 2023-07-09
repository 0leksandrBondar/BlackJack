#include "gameController.h"

#include "cards/abstractcard.h"
#include "graphicsItems/label.h"
#include "graphicsItems/newcardwidget.h"
#include "players/dealer.h"
#include "players/player.h"
#include "scene/scene.h"

#include <QDebug>
#include <QGraphicsItem>
#include <random>

namespace Constants
{
const auto distanceBetweenCards = 40;
const QPointF newCardWidgetPos = { 1000, 230 };
const QPointF playerLabelPos = { 400,435 };
const QPointF dealerLabelPos = { 400,195 };
} // namespace Constants

GameController::GameController(Scene *scene)
    : QObject(nullptr),
      _scene(scene),
      _player(new Player()),
      _dealer(new Dealer()),
      _playerLabel(new Label("player: ")),
      _dealerLabel(new Label("dealer: ")),
      _newCardWidget(new NewCardWidget()),
      _cardStack(_newCardWidget->initCardStack())
{
    addLabelsOnScene();
    _scene->addItem(_newCardWidget);
    _newCardWidget->setPos(Constants::newCardWidgetPos);
    connect(this, &GameController::playerReceivedCards, this, &GameController::addNewCardToDealer);
}

GameController::~GameController()
{
    delete _player;
    delete _dealer;
}

void GameController::onClickedNewCardWidget()
{
    const auto newCard = getNewCardFromStack();

    newCard->setPos(_defaultPlayerCardPos);
    _scene->addItem(newCard);

    _player->addCard(newCard->cardType().second);
    _playerLabel->setPlainText(QStringLiteral("player: %1").arg(QString::number(_player->score())));

    _defaultPlayerCardPos.setX(_defaultPlayerCardPos.x() + Constants::distanceBetweenCards);

    emit playerReceivedCards();
}

void GameController::addNewCardToDealer()
{
    auto newCard = getNewCardFromStack();

    newCard->setPos(_defaultDealerCardPos);
    _scene->addItem(newCard);
    newCard->setCardVisible(false);

    _dealer->addCard(newCard->cardType().second);
    _dealerLabel->setPlainText(QStringLiteral("dealer: %1").arg(QString::number(_dealer->score())));

    _defaultDealerCardPos.setX(_defaultDealerCardPos.x() + Constants::distanceBetweenCards);
}

AbstractCard *GameController::getNewCardFromStack()
{
    if (_cardStack.empty())
        return nullptr;

    const auto newCard = (_cardStack.front());
    _cardStack.erase(_cardStack.begin());

    return newCard;
}

void GameController::addLabelsOnScene()
{
    _scene->addItem(_playerLabel);
    _playerLabel->setPos(Constants::playerLabelPos);
    _scene->addItem(_dealerLabel);
    _dealerLabel->setPos(Constants::dealerLabelPos);
}
