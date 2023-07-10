#include "scene.h"

#include "graphicsItems/newcardwidget.h"

#include <QGraphicsSceneMouseEvent>
#include <QDebug>

namespace Constants
{
const QRectF sceneRect = { 0, 0, 1200, 640 };
} // namespace Constants

Scene::Scene(QObject *parent)
    : QGraphicsScene(parent)
{
    setSceneRect(Constants::sceneRect);
    setBackgroundImage(QStringLiteral(":/fon.jpg"));
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
