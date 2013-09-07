#-------------------------------------------------
#
# Project created by QtCreator 2013-09-07T18:50:04
#
#-------------------------------------------------

QT += core

QT -= gui

TARGET = laletests
CONFIG += console qxt qtestlib
CONFIG -= app_bundle
QXT += core gui

TEMPLATE = app

INCLUDEPATH += ../../src/lale
DEPENDPATH += ../../src/lale
RESOURCES = testdata.qrc \
    testdata.qrc

# logic sources/headers
SOURCES += \
    core/questionreader.cpp \
    core/question.cpp
HEADERS  += \
    core/questionreader.h \
    core/question.h


# test sources/headers
SOURCES += main.cpp \
    core/questionreadertest.cpp

HEADERS  += \
    core/questionreadertest.h
