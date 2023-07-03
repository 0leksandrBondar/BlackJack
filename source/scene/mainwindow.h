#pragma once

#include <QMainWindow>

class SceneView;
class GameWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);

private:
    void setupUI();

private:
    SceneView *_sceneView{ nullptr };
    GameWidget *_gameWidget{ nullptr };
};
