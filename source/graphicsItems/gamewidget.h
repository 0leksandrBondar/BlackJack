#pragma once

#include <QWidget>

class QLabel;
class QPushButton;
class QGridLayout;
class QHBoxLayout;

enum class RoundResult;

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    GameWidget(QWidget *parent = nullptr);
    void handleWinLabels(RoundResult roundResult, int newBalance);

    void updateBalanceLabel(int pot, int newPlayerBalance);
    void updateBalanceLabelAfterWin(QString emptyValue);
    void resetVictoryLabel();

private:
    void setGridUi();
    void initFields();
    void addItemsOnWidget();
    void setStyleForItemsOnWidgets();

private:
    QLabel *_balanceLabel;
    QLabel *_potLabel;
    QGridLayout *_layout;
    QLabel *_victoryLabel;
    QPushButton *_homeButton;
    QPushButton *_soundButton;
    QHBoxLayout *_labelsLayout;
    QPushButton *_settingsButton;
};
