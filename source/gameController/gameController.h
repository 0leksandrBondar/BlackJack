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

enum class RoundResult
{
    PlayerIsWinner,
    DealerIsWinner,
    Tie
};

class GameController : public QObject
{
    Q_OBJECT
public:
    GameController(Scene *scene = nullptr);
    ~GameController();

    int playerBalance() const;
    void onClickedNewCardWidget();

signals:
    void isMatchTie(int newBalance);
    void playerIsWinner(int newBalance);
    void dealerIsWinner(int newBalance);
    void needUpadteScore();
    void playerReceivedCards();
    void betMade(int pot, int newBalance);
    void roundIsFinished(RoundResult roundResult, int newBalance);

private:
    void betAction();
    void stopAction();
    void restartGame();
    void updateScore();
    void addLabelsOnScene();
    void initGameTable();
    void addNewCardToDealer();
    void composeLogicWidgets();
    void openClosedDealerCards();
    void ComposeWidgetsOnScene();
    void checkWinner(int playerScore, int dealerScore);

    AbstractCard *getNewCardFromStack();

private:
    int _pot{ 0 };
    bool _cardVisible{ true };
    RoundResult _roundResult;

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
