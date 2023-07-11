#include "gameController.h"

#include "cards/abstractcard.h"
#include "graphicsItems/circlewidget.h"
#include "graphicsItems/label.h"
#include "graphicsItems/newcardwidget.h"
#include "players/dealer.h"
#include "players/player.h"
#include "scene/scene.h"

#include <QDebug>
#include <QGraphicsItem>
#include <random>

namespace Constants
{
const int betValue{ 5 };
QPointF dealerCardPos{ 400, 30 };
QPointF playerCardPos{ 400, 470 };
const auto distanceBetweenCards = 40;
const QPointF betLabelPos = { 40, 265 };
const QPointF betWidgetPos = { 30, 300 };
const QPointF stopWidgetPos = { 1000, 300 };
const QPointF playerLabelPos = { 400, 435 };
const QPointF dealerLabelPos = { 400, 195 };
const QPointF newCardWidgetPos = { 1000, 100 };
const QPointF restartWidgetPos = { 1000, 420 };
} // namespace Constants

GameController::GameController(Scene *scene)
    : QObject(nullptr),
      _scene(scene),
      _player(new Player()),
      _dealer(new Dealer()),
      _betLabel(new Label(QStringLiteral("bet: 5.00"))),
      _playerLabel(new Label(QStringLiteral("player: "))),
      _dealerLabel(new Label(QStringLiteral("dealer: "))),
      _betWidget(new CircleWidget(":/dib.png")),
      _stopWidget(new CircleWidget(":/stop.png")),
      _newCardWidget(new NewCardWidget()),
      _restartGame(new CircleWidget(":/restart.png")),
      _cardStack(_newCardWidget->initCardStack())
{
    ComposeWidgetsOnScene();
    composeLogicWidgets();
    connect(this, &GameController::needUpadteScore, this, &GameController::updateScore);
    connect(_scene, &Scene::clickOnAddCardWidget, this, &GameController::onClickedNewCardWidget);
    initGameTable();
}

GameController::~GameController()
{
    delete _scene;
    delete _player;
    delete _dealer;
    delete _betLabel;
    delete _betWidget;
    delete _dealerLabel;
    delete _playerLabel;
    delete _restartGame;
    delete _newCardWidget;
    delete _stopWidget;
}

void GameController::onClickedNewCardWidget()
{
    if (_player->score() >= 21 || _pot == 0)
        return;
    const auto newCard = getNewCardFromStack();

    newCard->setCardVisible(_cardVisible);
    newCard->setPos(Constants::playerCardPos);

    _scene->addItem(newCard);
    _player->addCard(newCard);

    Constants::playerCardPos.setX(Constants::playerCardPos.x() + Constants::distanceBetweenCards);

    emit needUpadteScore();
    if(_player->score() >= 21)
        stopAction();
    emit playerReceivedCards();
}

void GameController::resetPot() { _pot = 0; }

int GameController::playerBalance() const { return _player->balance(); }

void GameController::betAction()
{
    if(_player->balance() <= 0)
        return;
    const auto playerBalance = _player->balance();
    const auto newPlayerBalance = playerBalance - Constants::betValue;
    _player->updateBalance(newPlayerBalance);

    // Constants:: betValue * 2 because two players are betting (dealer and player)
    _pot += Constants::betValue * 2;
    emit betMade(_pot, _player->balance());
}

void GameController::stopAction()
{
    openClosedDealerCards();
    while (_dealer->score() <= 17)
    {
        addNewCardToDealer();
    }
    checkWinner(_player->score(), _dealer->score());
}

void GameController::restartGame()
{
    _player->resetScore();
    _dealer->resetScore();
    _dealer->clear();
    _player->clear();

    for (const auto cards : _scene->items())
    {
        if (dynamic_cast<AbstractCard *>(cards))
            _scene->removeItem(cards);
    }
    emit needUpadteScore();
    emit resetGame();
    initGameTable();
}

void GameController::composeLogicWidgets()
{
    _betWidget->onClick([this]() { betAction(); });
    _stopWidget->onClick([this]() { stopAction(); });
    _restartGame->onClick([this]() { restartGame(); });
}

void GameController::openClosedDealerCards()
{
    for (const auto dealerCard : _dealer->cards())
    {
        if (dealerCard->cardVisible() == false)
        {
            dealerCard->setCardVisible(true);
            dealerCard->update();
        }
    }
}

void GameController::addNewCardToDealer()
{
    auto newCard = getNewCardFromStack();

    newCard->setPos(Constants::dealerCardPos);
    _scene->addItem(newCard);

    _dealer->addCard(newCard);
    emit needUpadteScore();

    Constants::dealerCardPos.setX(Constants::dealerCardPos.x() + Constants::distanceBetweenCards);
}

AbstractCard *GameController::getNewCardFromStack()
{
    if (_cardStack.empty())
        return nullptr;

    const auto newCard = (_cardStack.front());
    _cardStack.erase(_cardStack.begin());

    return newCard;
}

void GameController::ComposeWidgetsOnScene()
{
    _scene->addItem(_newCardWidget);
    _scene->addItem(_betWidget);
    _scene->addItem(_stopWidget);
    _stopWidget->setPos(Constants::stopWidgetPos);
    _betWidget->setPos(Constants::betWidgetPos);
    _scene->addItem(_restartGame);
    _restartGame->setPos(Constants::restartWidgetPos);
    _newCardWidget->setPos(Constants::newCardWidgetPos);

    addLabelsOnScene();
}

void GameController::checkWinner(int playerScore, int dealerScore)
{
    const bool isPlayerWinner{ (playerScore > dealerScore && playerScore <= 21)
                               || (playerScore <= 21 && dealerScore > 21) };
    const bool isDealerWinner{ (dealerScore > playerScore && dealerScore <= 21)
                               || (playerScore > 21 && dealerScore <= 21) };
    const bool isTie{ (playerScore == dealerScore || (playerScore > 21 && dealerScore > 21)) };

    int newBalance = 0;

    if (isDealerWinner)
    {
        const auto playerBalance = _dealer->balance();
        const auto newPlayerBalance = playerBalance + _pot;

        _dealer->updateBalance(newPlayerBalance);
        _roundResult = RoundResult::DealerIsWinner;
        newBalance = _player->balance();
    }
    else
    {
        const auto playerBalance = _player->balance();
        int newPlayerBalance = 0;
        if (isPlayerWinner)
        {
            newPlayerBalance = playerBalance + _pot;
            _roundResult = RoundResult::PlayerIsWinner;
        }
        if (isTie)
        {
            newPlayerBalance = playerBalance + (_pot / 2);
            _roundResult = RoundResult::Tie;
        }
        _player->updateBalance(newPlayerBalance);
        newBalance = _player->balance();
    }

    resetPot();
    emit roundIsFinished(_roundResult, newBalance);
}

void GameController::initGameTable()
{
    Constants::dealerCardPos = { 400, 30 };
    Constants::playerCardPos = { 400, 470 };
    emit resetGame();

    _cardStack.clear();
    _cardStack = _newCardWidget->initCardStack();

    for (int i = 0; i < 2; ++i)
    {
        auto newCard = getNewCardFromStack();
        newCard->setPos(Constants::dealerCardPos);
        _dealer->addCard(newCard);
        _scene->addItem(newCard);

        Constants::dealerCardPos.setX(Constants::dealerCardPos.x()
                                      + Constants::distanceBetweenCards);
    }

    _dealer->cards().front()->setCardVisible(false);

    for (int i = 0; i < 2; ++i)
    {
        auto newCard = getNewCardFromStack();

        newCard->setPos(Constants::playerCardPos);

        _player->addCard(newCard);
        _scene->addItem(newCard);

        Constants::playerCardPos.setX(Constants::playerCardPos.x()
                                      + Constants::distanceBetweenCards);
    }
    emit needUpadteScore();
}

void GameController::updateScore()
{
    _player->calculateScore();
    _dealer->calculateScore();
    _dealerLabel->setPlainText(QStringLiteral("dealer: %1").arg(QString::number(_dealer->score())));
    _playerLabel->setPlainText(QStringLiteral("player: %1").arg(QString::number(_player->score())));
}

void GameController::addLabelsOnScene()
{
    _scene->addItem(_betLabel);
    _betLabel->setPos(Constants::betLabelPos);
    _scene->addItem(_playerLabel);
    _playerLabel->setPos(Constants::playerLabelPos);
    _scene->addItem(_dealerLabel);
    _dealerLabel->setPos(Constants::dealerLabelPos);
}
