
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
    app/dbmigratortest.cpp \
    core/questionreadertest.cpp \
    core/randomgeneratortest.cpp \
    core/roulettewheelselectortest.cpp \
    core/scorerepositorytest.cpp \
    core/statisticscalculatortest.cpp \
    learningstrategies/byrepetitionteachertest.cpp \
    learningstrategies/naiveteachertest.cpp \
    learningstrategies/questionsignalfetcher.cpp \
    learningstrategies/simpleteachertest.cpp \
    testhelpers/testcase.cpp

HEADERS  += \
    app/dbmigratortest.h \
    core/questionreadertest.h \
    core/randomgeneratortest.h \
    core/roulettewheelselectortest.h \
    core/scorerepositorytest.h \
    core/statisticscalculatortest.h \
    learningstrategies/byrepetitionteachertest.h \
    learningstrategies/naiveteachertest.h \
    learningstrategies/questionsignalfetcher.h \
    learningstrategies/simpleteachertest.h \
    testhelpers/testcase.h

# logic sources/headers
SOURCES += \
    app/dbmigrator.cpp \
    core/question.cpp \
    core/questionreader.cpp \
    core/randomgenerator.cpp \
    core/impl/randomgeneratorimpl.cpp \
    core/scorerepository.cpp \
    core/statisticscalculator.cpp \
    learningstrategies/byrepetitionteacher.cpp \
    learningstrategies/naiveteacher.cpp \
    learningstrategies/simpleteacher.cpp \
    learningstrategies/teacher.cpp

HEADERS += app/libs.h \
    app/dbmigrator.h \
    core/question.h \
    core/questionreader.h \
    core/randomgenerator.h \
    core/impl/randomgeneratorimpl.h \
    core/roulettewheelselector.h \
    core/scorerepository.h \
    core/statisticscalculator.h \
    learningstrategies/byrepetitionteacher.h \
    learningstrategies/naiveteacher.h \
    learningstrategies/simpleteacher.h \
    learningstrategies/teacher.h

