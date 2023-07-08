#include "gameController.h"

#include "cards/abstractcard.h"
#include "graphicsItems/newcardwidget.h"
#include "players/dealer.h"
#include "players/player.h"
#include "scene/scene.h"
#include "graphicsItems/label.h"

#include <QGraphicsItem>
#include <random>
#include <QDebug>

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
    _newCardWidget->setPos(1000, 230);
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
    const auto distanceBetweenCards = 40;

    newCard->setPos(_defaultPlayerCardPos);
    _player->addCard(newCard->cardType().second);
    _scene->addItem(newCard.get());
    _playerLabel->setPlainText("player: "  + QString::number(_player->score()));
    qDebug() <<  _scene->items().contains(newCard.get());


    _defaultPlayerCardPos.setX(_defaultPlayerCardPos.x() + distanceBetweenCards);

    emit playerReceivedCards();
}

void GameController::addNewCardToDealer()
{
    // this func must be refoctored and combined with onClickedNewCardWidget()
    auto newCard = getNewCardFromStack();
    const auto distanceBetweenCards = 40;

    _dealer->addCard(newCard->cardType().second);
   // newCard->setPos(_defaultDealerCardPos);
    _scene->addItem(newCard.get());
    _dealerLabel->setPlainText("dealer: " + QString::number(_dealer->score()));
    qDebug() <<  _scene->items().contains(newCard.get());

    _defaultDealerCardPos.setX(_defaultDealerCardPos.x() + distanceBetweenCards);
}


std::shared_ptr<AbstractCard> GameController::getNewCardFromStack()
{
    if (_cardStack.empty())
        return nullptr;

    auto newCard = (_cardStack.front());
    //_cardStack.erase(_cardStack.begin());

    return newCard;
}


void GameController::addLabelsOnScene()
{
    _scene->addItem(_playerLabel);
    _playerLabel->setPos(400,435);
    _scene->addItem(_dealerLabel);
    _dealerLabel->setPos(400,195);
}
