#include "gameController.h"

#include "cards/abstractcard.h"
#include "players/dealer.h"
#include "players/player.h"
#include "scene/scene.h"

#include <QGraphicsItem>

GameController::GameController(Scene *scene)
    : QObject(nullptr), _scene(scene), _player(new Player()), _dealer(new Dealer())
{
}

GameController::~GameController()
{
    delete _player;
    delete _dealer;
}

void GameController::onClickedNewCardWidget(AbstractCard *card)
{
    _player->addCard(card);
   // _dealer->addCard(card);
    card->setX(castomPos.x() + 25);
    card->setPos(castomPos);
    _scene->addItem(card);


}
