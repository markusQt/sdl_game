TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    game.cpp \
    texturemanager.cpp

LIBS += -L$$PWD/../../../../../usr/lib/x86_64-linux-gnu/ -lSDL2
LIBS += -L$$PWD/../../../../../usr/lib/x86_64-linux-gnu/ -lSDL2_image


INCLUDEPATH += $$PWD/../../../../../usr/include/SDL2
DEPENDPATH += $$PWD/../../../../../usr/include/SDL2

HEADERS += \
    game.h \
    texturemanager.h


