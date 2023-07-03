#include <QApplication>

#include "scene/mainwindow.h"

#include <map>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow m;
    m.show();


    std::map<int,std::string> _map;

    _map.insert({1,"a"});
    _map.insert({2,"b"});
    _map.insert({3,"c"});
    _map.insert({4,"d"});
    _map.insert({5,"e"});
    _map.insert({6,"f"});

    return app.exec();
}
