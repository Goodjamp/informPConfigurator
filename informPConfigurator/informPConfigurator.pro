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
           lcdstr.cpp \
           hidInterface.cpp \
           waitform.cpp \
           communicationclass.cpp \
           informptransportclass.cpp \
    clockconfig.cpp

HEADERS += mainwindow.h \
           lcdstr.h \
           controlelementdescription.h \
           hidInterface.h \
           informpmemmap.h \
           waitform.h \
           communicationclass.h \
           informptransportclass.h \
    clockconfig.h

FORMS   += mainwindow.ui \
           lcdstr.ui \
           waitform.ui \
    clockconfig.ui

LIBS    += -lhid\
           -lsetupapi\
           -lpthread

CONFIG  += c++11

QMAKE_LFLAGS += -static-libgcc
                -static-libstdc++
                -static-lstdc++
                -lpthread
