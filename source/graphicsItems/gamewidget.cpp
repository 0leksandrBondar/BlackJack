#include "gamewidget.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

GameWidget::GameWidget(QWidget *parent) : QWidget(parent) { setUI(); }

void GameWidget::setUI()
{
    QVBoxLayout *mainVerticalLayout = new QVBoxLayout(this);
    QHBoxLayout *mainHorzontalLayout = new QHBoxLayout(this);
    QHBoxLayout *victoryLayout = new QHBoxLayout;
    QHBoxLayout *homeButtonLayout = new QHBoxLayout;
    QHBoxLayout *settingsLayout = new QHBoxLayout;
    QHBoxLayout *labelsLayout = new QHBoxLayout;

    QPushButton *homeButton = new QPushButton(QStringLiteral("home"), this);
    QPushButton *settingsButton = new QPushButton(QStringLiteral("setting"), this);
    QPushButton *soundButton = new QPushButton(QStringLiteral("sound"), this);
    QLabel *betLabel = new QLabel(QStringLiteral("Balance: $1000"), this);
    QLabel *cashLabel = new QLabel(QStringLiteral("Cash: $1000"), this);
    QLabel *victoryLabel = new QLabel(QStringLiteral("here will be info about victory"), this);

    labelsLayout->addWidget(betLabel);
    labelsLayout->addWidget(cashLabel);

    homeButton->setFixedSize(50, 50);
    homeButtonLayout->addWidget(homeButton);
    soundButton->setFixedSize(50, 50);

    settingsButton->setFixedSize(50, 50);
    settingsLayout->addWidget(soundButton);
    settingsLayout->addWidget(settingsButton);

    victoryLayout->addWidget(victoryLabel);
    victoryLayout->setAlignment(Qt::AlignCenter);

    mainHorzontalLayout->addLayout(homeButtonLayout);

    mainHorzontalLayout->addLayout(victoryLayout);
    mainHorzontalLayout->addLayout(settingsLayout);

    QFont labelFont = victoryLabel->font();
    labelFont.setPointSize(20);
    victoryLabel->setFont(labelFont);

    mainVerticalLayout->addLayout(mainHorzontalLayout);
    mainVerticalLayout->addLayout(labelsLayout);
}
