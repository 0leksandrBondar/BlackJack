#include "settingwindow.h"

SettingWindow::SettingWindow(QWidget *parent) : QDialog(parent) {}

void SettingWindow::showSettingsWindow() { exec(); }
