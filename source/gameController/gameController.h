#pragma once

#include "dialogWindows/settingwindow.h"
#include "scene/scene.h"

#include <QObject>
#include <QPointF>
#include <memory>
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
	GameController(Scene* scene = nullptr);

	int playerBalance() const;
	void onClickedNewCardWidget();

	void changeTheme(CardTheme theme);

signals:
	void resetGame();
	void isMatchTie(int newBalance);
	void playerIsWinner(int newBalance);
	void dealerIsWinner(int newBalance);
	void needUpadteScore();
	void playerReceivedCards();
	void betMade(int pot, int newBalance);
	void roundIsFinished(RoundResult roundResult, int newBalance);

private:
	void resetPot();
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

	std::shared_ptr<AbstractCard> getNewCardFromStack();

private:
	int _pot{0};
	CardTheme _isCardThemeChanged{CardTheme::WhiteTheme};
	bool _cardVisible{true};
	RoundResult _roundResult;

	std::unique_ptr<Scene> _scene;
	std::unique_ptr<Player> _player;
	std::unique_ptr<Dealer> _dealer;
	std::unique_ptr<Label> _betLabel;
	std::unique_ptr<Label> _playerLabel;
	std::unique_ptr<Label> _dealerLabel;
	std::unique_ptr<CircleWidget> _betWidget;
	std::unique_ptr<CircleWidget> _stopWidget;
	std::unique_ptr<NewCardWidget> _newCardWidget;
	std::unique_ptr<CircleWidget> _restartGame;
	std::vector<std::shared_ptr<AbstractCard>> _cardStack;
};
