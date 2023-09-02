#pragma once

#include <QDialog>
class QLabel;
class QPushButton;

class SettingWindow : public QDialog
{
    Q_OBJECT
public:
    SettingWindow(QWidget *parent = nullptr);
    void showSettingsWindow();

private:
    QLabel *changeThemeLabel;
};
