
QT += core sql
QT -= gui

TARGET = laletests
CONFIG += console qxt qtestlib precompile_header debug
CONFIG -= app_bundle
QMAKE_CXXFLAGS_DEBUG += -D_GLIBCXX_DEBUG
QXT += core
PRECOMPILED_HEADER = app/libs.h
DEFINES += USING_PCH

TEMPLATE = app

INCLUDEPATH += ../../src/lale
DEPENDPATH += ../../src/lale


RESOURCES = testdata.qrc dbmigrations.qrc

# test sources/headers
SOURCES += main.cpp \
    core/questionreadertest.cpp \
    learningstrategies/naivelearnertest.cpp \
    learningstrategies/questionsignalfetcher.cpp \
    app/dbmigratortest.cpp \
    testhelpers/testcase.cpp \
    core/scorerepositorytest.cpp \
    core/roulettewheelselectortest.cpp \
    learningstrategies/simplelearnertest.cpp \
    core/randomgeneratortest.cpp

HEADERS  += \
    core/questionreadertest.h \
    learningstrategies/naivelearnertest.h \
    learningstrategies/questionsignalfetcher.h \
    app/dbmigratortest.h \
    testhelpers/testcase.h \
    core/scorerepositorytest.h \
    core/roulettewheelselectortest.h \
    learningstrategies/simplelearnertest.h \
    core/randomgeneratortest.h

# logic sources/headers
SOURCES += \
    core/questionreader.cpp \
    core/question.cpp \
    learningstrategies/learner.cpp \
    learningstrategies/naivelearner.cpp \
    learningstrategies/simplelearner.cpp \
    app/dbmigrator.cpp \
    core/scorerepository.cpp \
    core/randomgenerator.cpp

HEADERS += app/libs.h \
    core/questionreader.h \
    core/question.h \
    learningstrategies/learner.h \
    learningstrategies/naivelearner.h \
    learningstrategies/simplelearner.h \
    app/dbmigrator.h \
    core/scorerepository.h \
    core/roulettewheelselector.h \
    core/randomgenerator.h
