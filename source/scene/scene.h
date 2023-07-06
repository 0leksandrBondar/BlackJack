#pragma once

#include <QGraphicsScene>

class BetWidget;
class AbstractCard;
class NewCardWidget;
class GameController;
class CardVisibilityToggle;

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    Scene(QObject *parent = nullptr);


signals:
    void clickOnAddCardWidget(AbstractCard *card);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    void addBaseWidgetsOnScene();
    void setCustomPositionForBaseWidgets();
    void setBackgroundImage(const QString path);

    BetWidget *_betWidget;
    NewCardWidget *_newCardWidget;
    GameController *_gameController;
    CardVisibilityToggle *_cardVisitor;
};
