#include "gamewidget.h"

#include "dialogWindows/settingwindow.h"
#include "gameController/gameController.h"

#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

namespace DefaultText
{
const QString emptyValue{ QStringLiteral(" - ") };
const QString matchIsTie{ QStringLiteral("TIE!!") };
const QString hint{ QStringLiteral("Please make a bet") };
const QString playerIsWinner{ QStringLiteral("YOU WON!!") };
const QString dealerIsWinner{ QStringLiteral("YOU LOST!!") };
const QString potlabel = QStringLiteral(
    "<span style='color: green'>Pot:</span> <span style='color: yellow'>$%1</span>");
const QString balancelabel = QStringLiteral(
    "<span style='color: green'>Balance:</span> <span style='color: yellow'>$%1</span>");

} // namespace DefaultText

GameWidget::GameWidget(QWidget *parent)
    : QWidget(parent),
      _potLabel{ new QLabel(DefaultText::potlabel.arg(" - "), this) },
      _layout{ new QGridLayout(this) },
      _balanceLabel{ new QLabel(DefaultText::balancelabel.arg(25), this) },
      _victoryLabel{ new QLabel(DefaultText::hint, this) },
      _homeButton{ new QPushButton(QStringLiteral("home"), this) },
      _soundButton{ new QPushButton(QStringLiteral("sound"), this) },
      _labelsLayout{ new QHBoxLayout(this) },
      _settingsButton{ new QPushButton(QStringLiteral("setting"), this) },
      _settingWindow{ new SettingWindow(this) }
{
    QPalette pal = QPalette();

    pal.setColor(QPalette::Window, Qt::black);
    setAutoFillBackground(true);
    setPalette(pal);
    setGridUi();

    connect(_settingsButton.get(), &QPushButton::clicked, _settingWindow,
            &SettingWindow::showSettingsWindow);
}

void GameWidget::handleWinLabels(RoundResult roundResult, int newBalance)
{
    if (roundResult == RoundResult::PlayerIsWinner)
        _victoryLabel->setText(DefaultText::playerIsWinner);
    else if (roundResult == RoundResult::DealerIsWinner)
        _victoryLabel->setText(DefaultText::dealerIsWinner);
    else if (roundResult == RoundResult::Tie)
        _victoryLabel->setText(DefaultText::matchIsTie);

    _potLabel->setText(DefaultText::potlabel.arg(DefaultText::emptyValue));
    _balanceLabel->setText(DefaultText::balancelabel.arg(newBalance));
}

void GameWidget::updateBalanceLabel(int pot, int newPlayerBalance)
{
    _potLabel->setText(DefaultText::potlabel.arg(pot));
    _balanceLabel->setText(DefaultText::balancelabel.arg(newPlayerBalance));
}

void GameWidget::resetVictoryLabel() { _victoryLabel->setText(DefaultText::hint); }

void GameWidget::setGridUi()
{
    initFields();
    addItemsOnWidget();
    setStyleForItemsOnWidgets();
}

void GameWidget::initFields()
{
    const QString color{ "color: white;" };

    _potLabel->setStyleSheet(color);
    _balanceLabel->setStyleSheet(color);
    _victoryLabel->setStyleSheet(color);
}

void GameWidget::addItemsOnWidget()
{
    _labelsLayout->addWidget(_balanceLabel.get());
    _labelsLayout->addWidget(_potLabel.get());

    _layout->addWidget(_homeButton.get(), 0, 0);
    _layout->addWidget(_victoryLabel.get(), 0, 1, Qt::AlignCenter);
    _layout->addWidget(_soundButton.get(), 0, 2);
    _layout->addWidget(_settingsButton.get(), 0, 3);

    _layout->addLayout(_labelsLayout.get(), 1, 1, Qt::AlignCenter);
}

void GameWidget::setStyleForItemsOnWidgets()
{
    // set size
    const QSize fixedButtonSize{ 60, 60 };

    _homeButton->setFixedSize(fixedButtonSize);
    _soundButton->setFixedSize(fixedButtonSize);
    _settingsButton->setFixedSize(fixedButtonSize);

    // set Font
    QFont labelFont = _victoryLabel->font();
    labelFont.setPointSize(20);
    _victoryLabel->setFont(labelFont);
    _balanceLabel->setFont(labelFont);
    _potLabel->setFont(labelFont);

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
