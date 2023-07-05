#include "gameController.h"

#include "players/dealer.h"
#include "players/player.h"

GameController::GameController(Scene *scene)
    : _scene(scene), _player(new Player()), _dealer(new Dealer())
{
}

GameController::~GameController()
{
    delete _player;
    delete _dealer;
}
