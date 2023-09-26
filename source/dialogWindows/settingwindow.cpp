#include "settingwindow.h"

#include <QComboBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>

SettingWindow::SettingWindow(QWidget* parent) : QDialog(parent)
{
	initUi();
	connect(_listOfTheme, qOverload<int>(&QComboBox::currentIndexChanged),
		[this](int index)
		{
			_currentTheme = _listOfTheme->currentData().value<CardTheme>();
			qDebug() << "currentTheme = " << static_cast<int>(_currentTheme);
			emit changeTheme(_currentTheme);
		});
}

void SettingWindow::showSettingsWindow()
{
	exec();
}

void SettingWindow::initUi()
{
	resize(500, 550);
	setWindowTitle(QStringLiteral("Settings"));

	QVBoxLayout* mainLayout = new QVBoxLayout(this);
	QHBoxLayout* buttonLayout = new QHBoxLayout(this);

	_changeThemeLabel = new QLabel(QStringLiteral("Change card theme"), this);
	_changeThemeLabel->setFixedSize(190, 70);

	_listOfTheme = new QComboBox(this);
	_listOfTheme->setFixedSize(150, 30);
	_listOfTheme->addItem(QStringLiteral("White"), CardTheme::WhiteTheme);
	_listOfTheme->addItem(QStringLiteral("Dark"), CardTheme::DarkTheme);
	_currentTheme = CardTheme::WhiteTheme;

	mainLayout->addLayout(buttonLayout);
	mainLayout->addStretch();
	buttonLayout->addWidget(_changeThemeLabel);
	buttonLayout->addWidget(_listOfTheme);
	SetLabelColor();
	QFont labelFont = _changeThemeLabel->font();
	labelFont.setPointSize(15);
	_changeThemeLabel->setFont(labelFont);
}

void SettingWindow::paintEvent(QPaintEvent* event)
{
	QPixmap* pixmapBg = new QPixmap;
	pixmapBg->load(":/fon.jpg");

	QPixmap pixmapBgL = pixmapBg->scaled(this->size());
	QPalette palette;
	palette.setBrush(backgroundRole(), pixmapBgL);
	this->setPalette(palette);
}

void SettingWindow::SetLabelColor()
{
	const QString color{"color: white;"};
	_changeThemeLabel->setStyleSheet(color);
}
