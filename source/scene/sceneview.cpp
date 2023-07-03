#include "sceneview.h"

#include "scene.h"

SceneView::SceneView(QWidget *parent) : QGraphicsView(parent), _scene{ new Scene(parent) }
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(_scene);
    setDragMode(QGraphicsView::NoDrag);
    // Вимкнути центрування QGraphicsView
    //setAlignment(Qt::AlignLeft | Qt::AlignTop);

}

void SceneView::resizeEvent(QResizeEvent *event)
{
    QGraphicsView::resizeEvent(event);
    fitSceneToView();
}

void SceneView::fitSceneToView()
{
    if (scene()) {
        QRectF rect = scene()->itemsBoundingRect();
        setSceneRect(rect);
    }
}
