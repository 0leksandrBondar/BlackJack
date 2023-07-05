#pragma once

#include <QGraphicsScene>

class BetWidget;
class NewCardWidget;
class GameController;
class CardVisibilityToggle;

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    Scene(QObject *parent = nullptr);

private:
    void addBaseWidgetsOnScene();
    void setCustomPositionForBaseWidgets();
    void setBackgroundImage(const QString path);

    BetWidget *_betWidget;
    NewCardWidget *_newCardWidget;
    GameController *_gameController;
    CardVisibilityToggle *_cardVisitor;
};
