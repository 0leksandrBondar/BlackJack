#include "scene.h"

#include "gameController/gameController.h"
#include "graphicsItems/betwidget.h"
#include "graphicsItems/cardvisibilitytoggle.h"
#include "graphicsItems/newcardwidget.h"

#include <QGraphicsSceneMouseEvent>

#include <QDebug>

namespace Constants
{
const QPointF betWidgetPos = { 30, 300 };
const QRectF sceneRect = { 0, 0, 1200, 640 };
const QPointF cardVisitorPos = { 1000, 400 };
} // namespace Constants

Scene::Scene(QObject *parent)
    : QGraphicsScene(parent),
      _betWidget(new BetWidget()),
      _gameController(new GameController(this)),
      _cardVisitor(new CardVisibilityToggle())
{
    setSceneRect(Constants::sceneRect);
    addBaseWidgetsOnScene();
    setCustomPositionForBaseWidgets();
    setBackgroundImage(QStringLiteral(":/fon.jpg"));
    connect(this, &Scene::clickOnAddCardWidget, _gameController,
            &GameController::onClickedNewCardWidget);
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
                emit clickOnAddCardWidget();
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
    addItem(_cardVisitor);
}

void Scene::setCustomPositionForBaseWidgets()
{
    using namespace Constants;
    _betWidget->setPos(betWidgetPos);
    _cardVisitor->setPos(cardVisitorPos);
}
