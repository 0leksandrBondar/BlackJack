#pragma once

#include <QObject>
#include <QPointF>

#include <vector>

class Scene;
class Label;
class Dealer;
class Player;
class CircleWidget;
class AbstractCard;
class NewCardWidget;
class CardVisibilityToggle;

class GameController : public QObject
{
    Q_OBJECT
public:
    GameController(Scene *scene = nullptr);
    ~GameController();

    void onClickedNewCardWidget();
    void onClickOnVisibilityToggleWidget();

signals:
    void isMatchTie();
    void playerIsWinner();
    void dealerIsWinner();
    void needUpadteScore();
    void playerReceivedCards();

private:
    void stopAction();
    void restartGame();
    void updateScore();
    void addLabelsOnScene();
    void prepareGameTable();
    void addNewCardToDealer();
    void composeLogicWidgets();
    void openClosedDealerCards();
    void ComposeWidgetsOnScene();
    void checkWinner(int playerScore, int dealerScore);

    AbstractCard *getNewCardFromStack();

private:
    bool _cardVisible{ true };

    Scene *_scene;
    Player *_player;
    Dealer *_dealer;
    Label *_betLabel;
    Label *_playerLabel;
    Label *_dealerLabel;
    CircleWidget *_betWidget;
    CircleWidget *_stopWidget;
    NewCardWidget *_newCardWidget;
    CircleWidget *_restartGame;
    std::vector<AbstractCard *> _cardStack;
};
