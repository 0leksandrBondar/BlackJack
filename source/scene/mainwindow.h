#pragma once

#include <QMainWindow>

#include <memory>

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
    std::shared_ptr<Scene> _scene{ nullptr };
    std::shared_ptr<GameController> _gameController{ nullptr };
    std::shared_ptr<SceneView> _sceneView{ nullptr };
    std::shared_ptr<GameWidget> _gameWidget{ nullptr };
};
