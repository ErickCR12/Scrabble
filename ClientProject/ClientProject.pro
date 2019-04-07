#-------------------------------------------------
#
# Project created by QtCreator 2019-03-27T18:50:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ClientProject
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES  += main.cpp\
            clientlogic/Player.cpp\
            clientlogic/Board.cpp\
            json/PlayerMessage.cpp \
            tests/PlayerTest.cpp \
            gui/MainWindow.cpp \
            gui/JoinGameWindow.cpp \
            gui/CreateGameWindow.cpp \
            gui/DraggableTile.cpp \
            gui/ScrabbleWindow.cpp \
            socketcomunication/socketcliente.cpp

HEADERS  +=\
            clientlogic/Player.hpp\
            clientlogic/Board.hpp\
            json/PlayerMessage.hpp \
            tests/PlayerTest.hpp \
            gui/MainWindow.h \
            gui/JoinGameWindow.h \
            gui/CreateGameWindow.h \
            gui/DraggableTile.h \
            gui/ScrabbleWindow.h \
            socketcomunication/socketcliente.h

FORMS    += \
            gui/MainWindow.ui \
            gui/JoinGameWindow.ui \
            gui/CreateGameWindow.ui \
            gui/ScrabbleWindow.ui

LIBS += -L"$$_PRO_FILE_PWD_/lib/rapidjson"
