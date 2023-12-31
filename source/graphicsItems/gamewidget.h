#pragma once

#include "dialogWindows/settingwindow.h"

#include <QWidget>
#include <memory>

class QLabel;
class QPushButton;
class QGridLayout;
class QHBoxLayout;

class SettingWindow;
enum class RoundResult;

class GameWidget : public QWidget
{
	Q_OBJECT
public:
	GameWidget(QWidget* parent = nullptr);
	void handleWinLabels(RoundResult roundResult, int newBalance);

	void updateBalanceLabel(int pot, int newPlayerBalance);
	void updateBalanceLabelAfterWin(QString emptyValue);
	void resetVictoryLabel();
signals:
	void requestChangeTheme(CardTheme theme);

private:
	void setGridUi();
	void initFields();
	void addItemsOnWidget();
	void setStyleForItemsOnWidgets();

private:
	std::shared_ptr<QLabel> _potLabel;
	std::shared_ptr<QGridLayout> _layout;
	std::shared_ptr<QLabel> _balanceLabel;
	std::shared_ptr<QLabel> _victoryLabel;
	std::shared_ptr<QPushButton> _homeButton;
	std::shared_ptr<QPushButton> _soundButton;
	std::shared_ptr<QHBoxLayout> _labelsLayout;
	std::shared_ptr<QPushButton> _settingsButton;
	SettingWindow* _settingWindow;
};
