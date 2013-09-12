
QT += core sql
QT -= gui

TARGET = lalebenchmarks
CONFIG += console qxt qtestlib precompile_header
CONFIG -= app_bundle
QXT += core
PRECOMPILED_HEADER = app/libs.h
DEFINES += USING_PCH

TEMPLATE = app

INCLUDEPATH += ../../src/lale
DEPENDPATH += ../../src/lale


# benchmark sources/headers \
SOURCES += main.cpp \
    core/roulettewheelbenchmark.cpp

HEADERS += \
    core/roulettewheelbenchmark.h


# logic sources/headers
SOURCES += \
    core/randomgenerator.cpp

HEADERS += app/libs.h \
    core/roulettewheelselector.h \
    core/roulettearea.h \
    core/randomgenerator.h
