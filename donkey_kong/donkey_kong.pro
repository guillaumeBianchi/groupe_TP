#-------------------------------------------------
#
# Project created by QtCreator 2016-11-10T10:14:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = donkey_kong
TEMPLATE = app


SOURCES += main.cpp \
    myrect.cpp \
    enemy.cpp \
    donkeykong.cpp \
    ladders.cpp \
    levels.cpp

HEADERS  += \
    myrect.h \
    enemy.h \
    donkeykong.h \
    ladders.h \
    levels.h

FORMS    +=

RESOURCES += \
    ressources.qrc
