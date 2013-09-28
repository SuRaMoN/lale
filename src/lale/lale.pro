
QT += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lale
TEMPLATE = app
CONFIG += qxt precompile_header
QXT += core gui
PRECOMPILED_HEADER = app/libs.h
DEFINES += USING_PCH

RESOURCES = dbmigrations.qrc

SOURCES += main.cpp \
    app/application.cpp \
    core/question.cpp \
    core/questionreader.cpp \
    gui/mainwindow.cpp \
    core/scorerepository.cpp \
    app/dbmigrator.cpp \
    core/randomgenerator.cpp \
    learningstrategies/byrepetitionteacher.cpp \
    learningstrategies/teacher.cpp \
    learningstrategies/simpleteacher.cpp \
    learningstrategies/naiveteacher.cpp \
    gui/statisticswindow.cpp \
    core/statisticscalculator.cpp

HEADERS  += \
    app/application.h \
    core/question.h \
    core/questionreader.h \
    gui/mainwindow.h \
    core/scorerepository.h \
    app/dbmigrator.h \
    app/libs.h \
    core/roulettewheelselector.h \
    core/randomgenerator.h \
    learningstrategies/byrepetitionteacher.h \
    learningstrategies/teacher.h \
    learningstrategies/simpleteacher.h \
    learningstrategies/naiveteacher.h \
    gui/statisticswindow.h \
    core/statisticscalculator.h \
    core/statistics.h

FORMS += \
    gui/mainwindow.ui \
    gui/statisticswindow.ui
