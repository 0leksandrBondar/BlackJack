#include "gamewidget.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

GameWidget::GameWidget(QWidget *parent) : QWidget(parent) { setUI(); }

void GameWidget::setUI()
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    QHBoxLayout *Labellayout = new QHBoxLayout(this);

    QLabel *betLabel = new QLabel(QStringLiteral("Balance: $1000"), this);
    Labellayout->addWidget(betLabel);

    QLabel *cashLabel = new QLabel(QStringLiteral("Balance: $1000"), this);
    Labellayout->addWidget(cashLabel);

    layout->addLayout(Labellayout);

    QPushButton *homeButton = new QPushButton(QStringLiteral("home"), this);
    layout->addWidget(homeButton);

    QPushButton *soundButton = new QPushButton(QStringLiteral("home"), this);
    layout->addWidget(soundButton);

    QPushButton *moreButton = new QPushButton(QStringLiteral("more"), this);
    layout->addWidget(moreButton);
}
