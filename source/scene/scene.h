#pragma once

#include <QGraphicsScene>

#include <memory>

class BetWidget;
class AbstractCard;
class GameController;
class CardVisibilityToggle;

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    Scene(QObject *parent = nullptr);

signals:
   void clickOnAddCardWidget();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    void addBaseWidgetsOnScene();
    void setCustomPositionForBaseWidgets();
    void setBackgroundImage(const QString path);

    BetWidget *_betWidget;
    GameController *_gameController;
    CardVisibilityToggle *_cardVisitor;
};
