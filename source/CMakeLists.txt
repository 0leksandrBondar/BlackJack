cmake_minimum_required(VERSION 3.5)

set(SOURCES
    main.cpp
    scene/scene.cpp
    scene/sceneview.cpp
    scene/mainwindow.cpp
    gameController/gamewidget.cpp
    gameController/newcardwidget.cpp
    gameController/betwidget.cpp
    gameController/cardvisibilitytoggle.cpp
    cards/abstractcard.cpp
    model/cardmodel.cpp
    resource/frontcardimage.qrc
)

set(HEADERS
    scene/scene.h
    scene/sceneview.h
    scene/mainwindow.h
    gameController/gamewidget.h
    gameController/newcardwidget.h
    gameController/betwidget.h
    gameController/cardvisibilitytoggle.h
    cards/abstractcard.h
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
