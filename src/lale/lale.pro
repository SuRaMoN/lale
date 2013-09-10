
QT += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lale
TEMPLATE = app
CONFIG += qxt precompile_header
QXT += core gui
PRECOMPILED_HEADER = app/lale.h
DEFINES += USING_PCH

RESOURCES = dbmigrations.qrc

SOURCES += main.cpp \
    app/application.cpp \
    core/question.cpp \
    core/questionreader.cpp \
    gui/mainwindow.cpp \
    learningstrategies/naivelearner.cpp \
    learningstrategies/learner.cpp \
    core/scorerepository.cpp \
    app/dbmigrator.cpp \
    learningstrategies/simplelearner.cpp

HEADERS  += app/lale.h \
    app/application.h \
    core/question.h \
    core/questionreader.h \
    gui/mainwindow.h \
    learningstrategies/naivelearner.h \
    learningstrategies/learner.h \
    core/scorerepository.h \
    app/dbmigrator.h \
    app/lale.h \
    learningstrategies/simplelearner.h

FORMS += \
    gui/mainwindow.ui
