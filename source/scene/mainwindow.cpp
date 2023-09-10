#include "mainwindow.h"

#include "gameController/gameController.h"
#include "graphicsItems/gamewidget.h"
#include "scene.h"
#include "sceneview.h"

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, _scene(new Scene(this))
	, _gameController(new GameController(_scene.get()))
	, _sceneView(new SceneView(this))
	, _gameWidget(new GameWidget(this))
{
	setFixedSize(1200, 800);
	setupUI();
	initConnections();
	connect(_gameWidget.get(), &GameWidget::requestChangeTheme, _gameController.get(), &GameController::changeTheme);
}

void MainWindow::setupUI()
{
	_sceneView->setGeometry(0, 0, width(), height() * 0.8);
	_sceneView->setScene(_scene.get());

	_gameWidget->setGeometry(0, height() * 0.8, width(), height() * 0.2);

	QVBoxLayout* layout = new QVBoxLayout(this);
	layout->addWidget(_sceneView.get());
	layout->addWidget(_gameWidget.get());
}

void MainWindow::initConnections()
{
	connect(_gameController.get(), &GameController::betMade, _gameWidget.get(), &GameWidget::updateBalanceLabel);
	connect(_gameController.get(), &GameController::resetGame, _gameWidget.get(), &GameWidget::resetVictoryLabel);
	connect(_gameController.get(), &GameController::roundIsFinished, _gameWidget.get(), &GameWidget::handleWinLabels);
}
