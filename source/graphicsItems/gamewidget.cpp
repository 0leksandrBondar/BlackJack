#include "gamewidget.h"

#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

namespace DefaultText
{
const QString playerIsWinner{ QStringLiteral("YOU WON!!") };
const QString dealerIsWinner{ QStringLiteral("YOU LOST!!") };
const QString matchIsTie{ QStringLiteral("TIE!!") };
} // namespace DefaultText

GameWidget::GameWidget(QWidget *parent) : QWidget(parent)
{
    QPalette pal = QPalette();

    pal.setColor(QPalette::Window, Qt::black);
    setAutoFillBackground(true);
    setPalette(pal);
    setGridUi();
}

void GameWidget::handleWinLabels() { _victoryLabel->setText(DefaultText::playerIsWinner); }

void GameWidget::handleLoseLabels() { _victoryLabel->setText(DefaultText::dealerIsWinner); }

void GameWidget::handleTieLabels() { _victoryLabel->setText(DefaultText::matchIsTie); };

void GameWidget::setGridUi()
{
    initFields();
    addItemsOnWidget();
    setStyleForItemsOnWidgets();
}

void GameWidget::initFields()
{
    _layout = new QGridLayout(this);
    _labelsLayout = new QHBoxLayout(this);
    _homeButton = new QPushButton(QStringLiteral("home"), this);
    _cashLabel = new QLabel(QStringLiteral("Cash: $1000"), this);
    _soundButton = new QPushButton(QStringLiteral("sound"), this);
    _betLabel = new QLabel(QStringLiteral("Balance: $1000"), this);
    _settingsButton = new QPushButton(QStringLiteral("setting"), this);
    _victoryLabel = new QLabel(QStringLiteral("here will be info about victory"), this);

    _victoryLabel->setStyleSheet("color: white;");
    _cashLabel->setStyleSheet("color: white;");
    _betLabel->setStyleSheet("color: white;");
}

void GameWidget::addItemsOnWidget()
{
    _labelsLayout->addWidget(_betLabel);
    _labelsLayout->addWidget(_cashLabel);

    _layout->addWidget(_homeButton, 0, 0);
    _layout->addWidget(_victoryLabel, 0, 1, Qt::AlignCenter);
    _layout->addWidget(_soundButton, 0, 2);
    _layout->addWidget(_settingsButton, 0, 3);

    _layout->addLayout(_labelsLayout, 1, 1, Qt::AlignCenter);
}

void GameWidget::setStyleForItemsOnWidgets()
{
    // set size
    _homeButton->setFixedSize(60, 60);
    _soundButton->setFixedSize(60, 60);
    _settingsButton->setFixedSize(60, 60);

    // set Font
    QFont labelFont = _victoryLabel->font();
    labelFont.setPointSize(20);
    _victoryLabel->setFont(labelFont);
    _betLabel->setFont(labelFont);
    _cashLabel->setFont(labelFont);

    // set border and color
    QString roundButtonStyle
        = "QPushButton { "
          "border-radius: 25px; "
          "background-color: green; "
          "color: white; "
          "}";
    _homeButton->setStyleSheet(roundButtonStyle);
    _soundButton->setStyleSheet(roundButtonStyle);
    _settingsButton->setStyleSheet(roundButtonStyle);
}
