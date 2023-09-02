#include "settingwindow.h"

#include <QComboBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>

SettingWindow::SettingWindow(QWidget *parent) : QDialog(parent) { initUi(); }

void SettingWindow::showSettingsWindow() { exec(); }

void SettingWindow::initUi()
{
    resize(500, 550);
    setWindowTitle(QStringLiteral("Settings"));

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *buttonLayout = new QHBoxLayout(this);

    _changeThemeLabel = new QLabel(QStringLiteral("Change card theme"), this);
    _changeThemeLabel->setFixedSize(150, 30);

    QComboBox *listOfTheme = new QComboBox(this);
    listOfTheme->setFixedSize(100, 30);
    listOfTheme->addItem(QStringLiteral("Dark"));
    listOfTheme->addItem(QStringLiteral("White"));

    mainLayout->addLayout(buttonLayout);
    mainLayout->addStretch();
    buttonLayout->addWidget(_changeThemeLabel);
    buttonLayout->addWidget(listOfTheme);
}
