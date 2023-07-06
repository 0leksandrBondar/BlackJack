#pragma once

#include "qpoint.h"
#include <QObject>

class Scene;
class Dealer;
class Player;
class AbstractCard;

class GameController : public QObject
{
    Q_OBJECT
public:
    GameController(Scene *scene = nullptr);
    ~GameController();

    void onClickedNewCardWidget(AbstractCard *card);

private:
    QPointF castomPos = {500,500};
    Scene *_scene;
    Player *_player;
    Dealer *_dealer;
};
