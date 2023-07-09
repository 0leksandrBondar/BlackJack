#include <QApplication>

#include "scene/mainwindow.h"

#include <map>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow m;
    m.show();

    return app.exec();
}
