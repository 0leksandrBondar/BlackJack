#pragma once

#include <QDialog>

class SettingWindow : public QDialog
{
    Q_OBJECT
public:
    SettingWindow(QWidget *parent = nullptr);
    void showSettingsWindow();
};
