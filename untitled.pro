#-------------------------------------------------
#
# Project created by QtCreator 2014-05-04T19:07:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BlackConsol
TEMPLATE = app


SOURCES += main.cpp \
        mainwindow.cpp \
        consolecontrol.cpp \
        consolecommand.cpp \
    core.cpp

HEADERS  += mainwindow.h \
        consolecontrol.h \
        consolecommand.h \
    core.h

FORMS    += mainwindow.ui
