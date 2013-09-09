#-------------------------------------------------
#
# Project created by QtCreator 2013-09-07T18:50:04
#
#-------------------------------------------------

QT += core sql

QT -= gui

TARGET = laletests
CONFIG += console qxt qtestlib
CONFIG -= app_bundle
QXT += core gui

TEMPLATE = app

INCLUDEPATH += ../../src/lale
DEPENDPATH += ../../src/lale

RESOURCES = testdata.qrc

# test sources/headers
SOURCES += main.cpp \
    core/questionreadertest.cpp \
    learningstrategies/naivelearnertest.cpp \
    learningstrategies/questionsignalfetcher.cpp \
    app/dbmigratortest.cpp

HEADERS  += \
    core/questionreadertest.h \
    learningstrategies/naivelearnertest.h \
    learningstrategies/questionsignalfetcher.h \
    app/dbmigratortest.h

# logic sources/headers
SOURCES += \
    core/questionreader.cpp \
    core/question.cpp \
    learningstrategies/learner.cpp \
    learningstrategies/naivelearner.cpp \
    app/dbmigrator.cpp

HEADERS  += \
    core/questionreader.h \
    core/question.h \
    learningstrategies/learner.h \
    learningstrategies/naivelearner.h \
    app/dbmigrator.h

