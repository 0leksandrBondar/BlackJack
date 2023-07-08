#pragma once

#include <QObject>
#include <QPointF>

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

signals:
    void playerReceivedCards();

private:
    void addNewCardToDealer();
    std::shared_ptr<AbstractCard> getNewCardFromStack();

    void addLabelsOnScene();

private:
    Scene *_scene;
    Player *_player;
    Dealer *_dealer;
    Label *_playerLabel;
    Label *_dealerLabel;
    NewCardWidget *_newCardWidget;
    QPointF _defaultDealerCardPos{ 400, 30 };
    QPointF _defaultPlayerCardPos{ 400, 470 };
    std::vector<std::shared_ptr<AbstractCard>> _cardStack;
};
