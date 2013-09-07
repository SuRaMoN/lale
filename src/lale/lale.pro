#-------------------------------------------------
#
# Project created by QtCreator 2013-09-07T17:42:14
#
#-------------------------------------------------

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lale
TEMPLATE = app
CONFIG += qxt
QXT += core gui

SOURCES += main.cpp \
    gui/mainwindow.cpp \
    application.cpp \
    core/question.cpp \
    core/questionreader.cpp

HEADERS  += \
    gui/mainwindow.h \
    application.h \
    core/question.h \
    core/questionreader.h

FORMS    += \
    gui/mainwindow.ui
