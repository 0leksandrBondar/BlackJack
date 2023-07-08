#include "gameController.h"

#include "cards/abstractcard.h"
#include "graphicsItems/newcardwidget.h"
#include "players/dealer.h"
#include "players/player.h"
#include "scene/scene.h"
#include "graphicsItems/label.h"

#include <QGraphicsItem>
#include <random>

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
}

GameController::~GameController()
{
    delete _player;
    delete _dealer;
}

void GameController::onClickedNewCardWidget()
{
    const auto newCard = getNewCardFromStack();
    const auto itemsOnScene = _scene->items();

    bool cardExistsOnScene = false;

    for (const auto item : itemsOnScene)
    {
        const auto cardItem = dynamic_cast<AbstractCard *>(item);
        if (cardItem && newCard->cardType() == cardItem->cardType())
        {
            cardExistsOnScene = true;
            break;
        }
    }

    if (!cardExistsOnScene)
    {
        const auto distanceBetweenCards = 40;

        _player->addCard(newCard);

        _scene->addItem(newCard);

        newCard->setPos(_defaultPlayerCardPos);

        _defaultPlayerCardPos.setX(_defaultPlayerCardPos.x() + distanceBetweenCards);
    }
    else
    {
        onClickedNewCardWidget();
    }
}



AbstractCard *GameController::getNewCardFromStack()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> dis(0, _cardStack.size() - 1);
    size_t randomIndex = dis(gen);

    AbstractCard *newCard = _cardStack[randomIndex].get();

    return newCard;
}

void GameController::addLabelsOnScene()
{
    _scene->addItem(_playerLabel);
    _playerLabel->setPos(400,435);
    _scene->addItem(_dealerLabel);
    _dealerLabel->setPos(400,195);
}
