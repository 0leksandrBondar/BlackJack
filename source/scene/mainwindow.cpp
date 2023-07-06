#include "mainwindow.h"
#include "graphicsItems/gamewidget.h"
#include "sceneview.h"

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), _sceneView(new SceneView(this)), _gameWidget(new GameWidget(this))
{
    setFixedSize(1200, 800);
    _sceneView->setGeometry(0, 0, width(), height() * 0.8);
    _gameWidget->setGeometry(0, height() * 0.8, width(), height() * 0.2);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(_sceneView);
    layout->addWidget(_gameWidget);
}
