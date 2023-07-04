#include "sceneview.h"

#include "scene.h"

SceneView::SceneView(QWidget *parent) : QGraphicsView(parent), _scene{ new Scene(parent) }
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(_scene);
}

