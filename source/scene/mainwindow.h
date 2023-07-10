#pragma once

#include <QMainWindow>

class Scene;
class SceneView;
class GameWidget;
class GameController;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);


private:
    void setupUI();
    void initConnections();

private:
    Scene *_scene{ nullptr };
    GameController *_gameController{ nullptr };
    SceneView *_sceneView{ nullptr };
    GameWidget *_gameWidget{ nullptr };
};
