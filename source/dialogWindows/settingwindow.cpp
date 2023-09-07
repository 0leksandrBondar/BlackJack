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
    //setStyleSheet( "background-image:url(:/settingsFon.jpg); background-size: cover; " );

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *buttonLayout = new QHBoxLayout(this);

    _changeThemeLabel = new QLabel(QStringLiteral("Change card theme"), this);
    _changeThemeLabel->setFixedSize(190, 70);

    QComboBox *listOfTheme = new QComboBox(this);
    listOfTheme->setFixedSize(150, 30);
    listOfTheme->addItem(QStringLiteral("White"));
    listOfTheme->addItem(QStringLiteral("Dark"));

    mainLayout->addLayout(buttonLayout);
    mainLayout->addStretch();
    buttonLayout->addWidget(_changeThemeLabel);
    buttonLayout->addWidget(listOfTheme);
    colorLabel();
 QFont labelFont = _changeThemeLabel->font();
    labelFont.setPointSize(15);
    _changeThemeLabel->setFont(labelFont);

}
void SettingWindow::paintEvent(QPaintEvent *event){
    QPixmap *pixmapBg = new QPixmap;
    pixmapBg->load(":/fon.jpg");

    QPixmap pixmapBgL = pixmapBg->scaled(this->size());
        QPalette palette;
        palette.setBrush(backgroundRole(),pixmapBgL);
        this->setPalette(palette);
    }
void SettingWindow::colorLabel(){
    const QString color{ "color: white;" };
    _changeThemeLabel->setStyleSheet(color);
}



