#pragma once

#include <QGraphicsScene>

#include <memory>

class CircleWidget;
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
    void clickOnVisibilityToggleWidget();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    void setBackgroundImage(const QString path);
};
