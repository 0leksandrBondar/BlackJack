#include "scene.h"

#include "cards/abstractcard.h"
#include "gameController/betwidget.h"
#include "gameController/newcardwidget.h"
#include "model/cardsuit.h"

#include <QGraphicsSceneMouseEvent>

Scene::Scene(QObject *parent) : QGraphicsScene(parent)
{
    setSceneRect(0, 0, 1200, 640);

    setBackgroundBrush(QColorConstants::Svg::lightgreen);
    NewCardWidget *widget = new NewCardWidget();
    BetWidget *bigBet = new BetWidget();
    BetWidget *smallBet = new BetWidget();

    AbstractCard *card = new AbstractCard({ CardSuit::Clubs, CardValue::Five });

    card->moveBy(500, 475);
    bigBet->moveBy(50, 200);
    smallBet->moveBy(50, 320);
    widget->moveBy(980, 230);

    addItem(card);
    addItem(widget);
    addItem(bigBet);
    addItem(smallBet);
    setBackgroundImage(":/fon.jpg");
}

void Scene::setBackgroundImage(const QString path)
{
    QPixmap backgroundImage(path);
    if (backgroundImage.isNull())
        return;

    setBackgroundBrush(backgroundImage);
}
