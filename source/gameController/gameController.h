#pragma once

#include <QPointF>
#include <QObject>

#include <vector>

class Scene;
class Label;
class Dealer;
class Player;
class AbstractCard;
class NewCardWidget;

class GameController : public QObject
{
    Q_OBJECT
public:
    GameController(Scene *scene = nullptr);
    ~GameController();

    void onClickedNewCardWidget();
private:
    AbstractCard *getNewCardFromStack();
    void addLabelsOnScene();

private:
    Scene *_scene;
    Player *_player;
    Dealer *_dealer;
    Label *_playerLabel;
    Label *_dealerLabel;
    NewCardWidget *_newCardWidget;
    QPointF _defaultPlayerCardPos{ 400, 470 };
    std::vector<std::unique_ptr<AbstractCard>> _cardStack;
};
