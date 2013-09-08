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
    app/application.cpp \
    core/question.cpp \
    core/questionreader.cpp \
    gui/mainwindow.cpp \
    learningstrategies/naivelearner.cpp \
    learningstrategies/learner.cpp

HEADERS  += \
    app/application.h \
    core/question.h \
    core/questionreader.h \
    gui/mainwindow.h \
    learningstrategies/naivelearner.h \
    learningstrategies/learner.h

FORMS += \
    gui/mainwindow.ui
