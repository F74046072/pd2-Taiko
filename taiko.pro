#-------------------------------------------------
#
# Project created by QtCreator 2016-05-11T19:53:52
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = taiko
TEMPLATE = app

CONFIG += warn_on

SOURCES += main.cpp\
        mainwindow.cpp \
    Drum.cpp \
    choosemusic.cpp

HEADERS  += mainwindow.h \
    Drum.h \
    choosemusic.h

FORMS    += mainwindow.ui \
    choosemusic.ui

RESOURCES += \
    res.qrc
