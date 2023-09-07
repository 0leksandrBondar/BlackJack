#pragma once

#include <QDialog>

class QLabel;

class SettingWindow : public QDialog
{
    Q_OBJECT
public:
    SettingWindow(QWidget *parent = nullptr);
    void showSettingsWindow();
    void initUi();
protected:

 void paintEvent(QPaintEvent *event) override;
 void colorLabel();

private:
    QLabel *_changeThemeLabel;
};
