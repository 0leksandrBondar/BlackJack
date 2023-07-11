#pragma once

#include <QWidget>

class QLabel;
class QPushButton;

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    GameWidget(QWidget *parent = nullptr);
    void handleWinLabels();
    void handleLoseLabels();
    void handleTieLabels();

private:
    void setUI();

private:
    QLabel *_victoryLabel;
    QPushButton *_homeButton;
    QPushButton *_soundButton;
};
