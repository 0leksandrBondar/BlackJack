#pragma once

#include <QWidget>

class QLabel;
class QPushButton;
class QGridLayout;
class QHBoxLayout;

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    GameWidget(QWidget *parent = nullptr);
    void handleWinLabels();
    void handleLoseLabels();
    void handleTieLabels();

private:
    void setGridUi();
    void initFields();
    void addItemsOnWidget();
    void setStyleForItemsOnWidgets();

private:
    QLabel *_betLabel;
    QLabel *_cashLabel;
    QGridLayout *_layout;
    QLabel *_victoryLabel;
    QPushButton *_homeButton;
    QPushButton *_soundButton;
    QHBoxLayout *_labelsLayout;
    QPushButton *_settingsButton;
};
