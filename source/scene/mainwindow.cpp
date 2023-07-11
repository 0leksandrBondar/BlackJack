#include "mainwindow.h"
#include "gameController/gameController.h"
#include "graphicsItems/gamewidget.h"
#include "scene.h"
#include "sceneview.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      _scene(new Scene(this)),
      _gameController(new GameController(_scene)),
      _sceneView(new SceneView(this)),
      _gameWidget(new GameWidget(this))
{
    setFixedSize(1200, 800);
    setupUI();
    initConnections();
}

void MainWindow::setupUI()
{
    _sceneView->setGeometry(0, 0, width(), height() * 0.8);
    _sceneView->setScene(_scene);

    _gameWidget->setGeometry(0, height() * 0.8, width(), height() * 0.2);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(_sceneView);
    layout->addWidget(_gameWidget);
}

void MainWindow::initConnections()
{
    connect(_gameController, &GameController::betMade, _gameWidget,
            &GameWidget::updateBalanceLabel);
    connect(_gameController, &GameController::resetGame, _gameWidget,
            &GameWidget::resetVictoryLabel);
    connect(_gameController, &GameController::roundIsFinished, _gameWidget,
            &GameWidget::handleWinLabels);
}
