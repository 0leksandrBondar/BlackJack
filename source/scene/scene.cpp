#include "scene.h"

#include "cards/abstractcard.h"
#include "model/cardsuit.h"
#include "newcardwidget.h"
#include <QDebug>

#include <QGraphicsSceneMouseEvent>

Scene::Scene(QObject *parent) : QGraphicsScene(parent)
{
    setSceneRect(0,0,900,600);

    setBackgroundBrush(QColorConstants::Svg::lightgreen);
    NewCardWidget *widget = new NewCardWidget();

    AbstractCard *card = new AbstractCard({ CardSuit::Clubs, CardValue::Five });
    addItem(card);
    addItem(widget);
}

