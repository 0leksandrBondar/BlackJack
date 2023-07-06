cmake_minimum_required(VERSION 3.5)

set(SOURCES
    main.cpp
    scene/scene.cpp
    scene/sceneview.cpp
    scene/mainwindow.cpp
    graphicsItems/gamewidget.cpp
    graphicsItems/newcardwidget.cpp
    graphicsItems/betwidget.cpp
    graphicsItems/cardvisibilitytoggle.cpp
    graphicsItems/label.cpp
    gameController/gameController.cpp
    cards/abstractcard.cpp
    players/player.cpp
    players/dealer.cpp
    players/abstractplayer.cpp
    model/cardmodel.cpp
    resource/frontcardimage.qrc
)

set(HEADERS
    scene/scene.h
    scene/sceneview.h
    scene/mainwindow.h
    graphicsItems/gamewidget.h
    graphicsItems/newcardwidget.h
    graphicsItems/betwidget.h
    graphicsItems/cardvisibilitytoggle.h
    graphicsItems/label.h
    gameController/gameController.h
    cards/abstractcard.h
    players/dealer.h
    players/player.h
    players/abstractplayer.h
    model/cardmodel.h
    model/cardsuit.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME}
  PRIVATE
   Qt6::Widgets
   Qt6::Core
)

qt6_add_resources(RESOURCES resource/frontcardimage.qrc)
target_sources(${PROJECT_NAME} PRIVATE ${RESOURCES})
