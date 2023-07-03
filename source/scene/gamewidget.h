#pragma once

#include <QWidget>

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    GameWidget(QWidget *parent = nullptr);

private:
    void setUI();
};
