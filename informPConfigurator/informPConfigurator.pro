#-------------------------------------------------
#
# Project created by QtCreator 2018-03-15T10:12:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = informPConfigurator
TEMPLATE = app


SOURCES += main.cpp\
           mainwindow.cpp \
           userhidinterfaces.cpp \
           lcdstr.cpp

HEADERS += mainwindow.h \
           userhidinterfaces.h \
    lcdstr.h \
    controlelementdescription.h

FORMS   += mainwindow.ui \
           lcdstr.ui \
    lcdstr.ui

LIBS    += -lhid\
           -lsetupapi

CONFIG  += c++11
