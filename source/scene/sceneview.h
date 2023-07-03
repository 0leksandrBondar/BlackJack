#pragma once

#include <QGraphicsView>

class Scene;

class SceneView : public QGraphicsView
{
    Q_OBJECT
public:
    SceneView(QWidget *parent = nullptr);
    void resizeEvent(QResizeEvent *event) override;
    void fitSceneToView();

private:
    Scene *_scene;
};
