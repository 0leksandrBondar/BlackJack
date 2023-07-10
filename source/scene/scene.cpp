#include "scene.h"

#include "gameController/gameController.h"
#include "graphicsItems/newcardwidget.h"

#include <QGraphicsSceneMouseEvent>

#include <QDebug>

namespace Constants
{
const QRectF sceneRect = { 0, 0, 1200, 640 };
} // namespace Constants

Scene::Scene(QObject *parent)
    : QGraphicsScene(parent),
      _gameController(new GameController(this))
{
    setSceneRect(Constants::sceneRect);
    setBackgroundImage(QStringLiteral(":/fon.jpg"));
    connect(this, &Scene::clickOnAddCardWidget, _gameController,
            &GameController::onClickedNewCardWidget);
    connect(this, &Scene::clickOnVisibilityToggleWidget, _gameController,
            &GameController::onClickOnVisibilityToggleWidget);
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

    QGraphicsScene::mousePressEvent(event);
}

void Scene::setBackgroundImage(const QString path)
{
    QPixmap backgroundImage(path);
    if (backgroundImage.isNull())
        return;

    setBackgroundBrush(backgroundImage);
}
