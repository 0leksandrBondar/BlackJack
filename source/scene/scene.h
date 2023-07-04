#pragma once

#include <QGraphicsScene>

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    Scene(QObject *parent = nullptr);
private:
    void setBackgroundImage(const QString path);


};
