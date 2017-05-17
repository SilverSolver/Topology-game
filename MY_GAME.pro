#-------------------------------------------------
#
# Project created by QtCreator 2017-05-10T22:34:46
#
#-------------------------------------------------

#QMAKE_CXXFLAGS_CXX11    = -std=c++11
QMAKE_CXXFLAGS += -std=c++11

QT       += core gui
CONFIG   += c++11
LIBS     += -Wl,-rpath,/home/laida/Qt/5.7/gcc_64/lib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MY_GAME
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    player.cpp \
    gameboard.cpp \
    gamecore.cpp \
    pathswitch.cpp \
    cell.cpp \
    levelwidget.cpp

HEADERS  += mainwindow.h \
    player.h \
    gameboard.h \
    gamecore.h \
    pathswitch.h \
    cell.h \
    levelwidget.h

FORMS    += mainwindow.ui
