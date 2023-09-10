#pragma once

#include <QComboBox>
#include <QDialog>

class QLabel;

class SettingWindow : public QDialog
{
	Q_OBJECT
public:
	SettingWindow(QWidget* parent = nullptr);
	void showSettingsWindow();
	void initUi();
	void foo();
signals:
	void changeTheme(int text);

protected:
	void paintEvent(QPaintEvent* event) override;
	void SetLabelColor();

private:
	QLabel* _changeThemeLabel;
	QComboBox* _listOfTheme;
	QString _currentTheme;
};
