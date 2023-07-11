#include "gamewidget.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

namespace DefaultText
{
const QString playerIsWinner{ QStringLiteral("YOU WON!!") };
const QString dealerIsWinner{ QStringLiteral("YOU LOST!!") };
const QString matchIsTie{ QStringLiteral("MATCH TIE!!") };
} // namespace DefaultText

GameWidget::GameWidget(QWidget *parent) : QWidget(parent) { setUI(); }

void GameWidget::handleWinLabels() { _victoryLabel->setText(DefaultText::playerIsWinner); }

void GameWidget::handleLoseLabels() { _victoryLabel->setText(DefaultText::dealerIsWinner); }

void GameWidget::handleTieLabels() { _victoryLabel->setText(DefaultText::matchIsTie); };

void GameWidget::setUI()
{
    QVBoxLayout *mainVerticalLayout = new QVBoxLayout(this);
    QHBoxLayout *mainHorzontalLayout = new QHBoxLayout(this);
    QHBoxLayout *victoryLayout = new QHBoxLayout;
    QHBoxLayout *homeButtonLayout = new QHBoxLayout;
    QHBoxLayout *settingsLayout = new QHBoxLayout;
    QHBoxLayout *labelsLayout = new QHBoxLayout;

    QPushButton *settingsButton = new QPushButton(QStringLiteral("setting"), this);
    _homeButton = new QPushButton(QStringLiteral("home"), this);
    _soundButton = new QPushButton(QStringLiteral("sound"), this);
    QLabel *betLabel = new QLabel(QStringLiteral("Balance: $1000"), this);
    QLabel *cashLabel = new QLabel(QStringLiteral("Cash: $1000"), this);
    _victoryLabel = new QLabel(QStringLiteral("here will be info about victory"), this);

    labelsLayout->addWidget(betLabel);
    labelsLayout->addWidget(cashLabel);

    _homeButton->setFixedSize(50, 50);
    homeButtonLayout->addWidget(_homeButton);
    _soundButton->setFixedSize(50, 50);

    settingsButton->setFixedSize(50, 50);
    settingsLayout->addWidget(_soundButton);
    settingsLayout->addWidget(settingsButton);

    victoryLayout->addWidget(_victoryLabel);
    victoryLayout->setAlignment(Qt::AlignCenter);

    mainHorzontalLayout->addLayout(homeButtonLayout);

    mainHorzontalLayout->addLayout(victoryLayout);
    mainHorzontalLayout->addLayout(settingsLayout);

    QFont labelFont = _victoryLabel->font();
    labelFont.setPointSize(20);
    _victoryLabel->setFont(labelFont);

    mainVerticalLayout->addLayout(mainHorzontalLayout);
    mainVerticalLayout->addLayout(labelsLayout);
}
