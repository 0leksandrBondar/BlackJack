#pragma once

class Scene;
class Dealer;
class Player;

class GameController
{
public:
    GameController(Scene *scene = nullptr);
    ~GameController();

private:
    Scene *_scene;
    Player *_player;
    Dealer *_dealer;
};
