#include "scene.h"

#include "gameController/betwidget.h"
#include "gameController/cardvisibilitytoggle.h"
#include "gameController/gameController.h"
#include "gameController/newcardwidget.h"

#include <QGraphicsSceneMouseEvent>

#include <QDebug>

namespace Constants
{
const QPointF betWidgetPos = { 30, 300 };
const QPointF defaultCardPos = { 500, 500 };
const QPointF cardVisitorPos = { 1000, 400 };
const QPointF newCardWidgetPos = { 1000, 230 };
} // namespace Constants

Scene::Scene(QObject *parent)
    : QGraphicsScene(parent),
      _betWidget(new BetWidget()),
      _newCardWidget(new NewCardWidget()),
      _gameController(new GameController(this)),
      _cardVisitor(new CardVisibilityToggle())
{
    setSceneRect(0, 0, 1200, 640);
    addBaseWidgetsOnScene();
    setCustomPositionForBaseWidgets();
    setBackgroundImage(QStringLiteral(":/fon.jpg"));
    connect(this, &Scene::clickOnAddCardWidget, _gameController,  &GameController::onClickedNewCardWidget);
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        QPointF clickPos = event->scenePos();

        QList<QGraphicsItem *> Items = items(clickPos);

        for (QGraphicsItem *item : Items)
        {
            if (dynamic_cast<NewCardWidget *>(item))
                emit clickOnAddCardWidget(_newCardWidget->getNewCard());
        }
    }
}

void Scene::setBackgroundImage(const QString path)
{
    QPixmap backgroundImage(path);
    if (backgroundImage.isNull())
        return;

    setBackgroundBrush(backgroundImage);
}

void Scene::addBaseWidgetsOnScene()
{
    addItem(_betWidget);
    addItem(_newCardWidget);
    addItem(_cardVisitor);
}

void Scene::setCustomPositionForBaseWidgets()
{
    using namespace Constants;
    _betWidget->setPos(betWidgetPos);
    _cardVisitor->setPos(cardVisitorPos);
    _newCardWidget->setPos(newCardWidgetPos);
}
