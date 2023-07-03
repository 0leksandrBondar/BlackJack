cmake_minimum_required(VERSION 3.5)

set(SOURCES
    main.cpp
    scene/scene.cpp
    scene/sceneview.cpp
    scene/mainwindow.cpp
    scene/gamewidget.cpp
    scene/newcardwidget.cpp
    cards/abstractcard.cpp
    model/cardmodel.cpp
)

set(HEADERS
    scene/scene.h
    scene/sceneview.h
    scene/mainwindow.h
    scene/gamewidget.h
    scene/newcardwidget.h
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
