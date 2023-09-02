#include "settingwindow.h"
#include <QComboBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>

SettingWindow::SettingWindow(QWidget *parent) : QDialog(parent)
{
    resize(500, 550);
    setWindowTitle("Settings");

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    changeThemeLabel = new QLabel("Change card theme", this);
    changeThemeLabel->setFixedSize(150, 30);

    QComboBox *listOfTheme = new QComboBox(this);
    listOfTheme->setFixedSize(100, 30);
    listOfTheme->addItem(QStringLiteral("Dark"));
    listOfTheme->addItem(QStringLiteral("White"));

    mainLayout->addLayout(buttonLayout);
    mainLayout->addStretch();
    buttonLayout->addWidget(changeThemeLabel);
    buttonLayout->addWidget(listOfTheme);
}

void SettingWindow::showSettingsWindow() { exec(); }
