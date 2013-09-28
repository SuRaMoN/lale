
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
    learningstrategies/questionsignalfetcher.cpp \
    app/dbmigratortest.cpp \
    testhelpers/testcase.cpp \
    core/scorerepositorytest.cpp \
    core/roulettewheelselectortest.cpp \
    core/randomgeneratortest.cpp \
    learningstrategies/byrepetitionteachertest.cpp \
    learningstrategies/naiveteachertest.cpp \
    learningstrategies/simpleteachertest.cpp

HEADERS  += \
    core/questionreadertest.h \
    learningstrategies/questionsignalfetcher.h \
    app/dbmigratortest.h \
    testhelpers/testcase.h \
    core/scorerepositorytest.h \
    core/roulettewheelselectortest.h \
    core/randomgeneratortest.h \
    learningstrategies/naiveteachertest.h \
    learningstrategies/byrepetitionteachertest.h \
    learningstrategies/simpleteachertest.h

# logic sources/headers
SOURCES += \
    core/questionreader.cpp \
    core/question.cpp \
    learningstrategies/teacher.cpp \
    learningstrategies/naiveteacher.cpp \
    learningstrategies/simpleteacher.cpp \
    learningstrategies/byrepetitionteacher.cpp \
    app/dbmigrator.cpp \
    core/scorerepository.cpp \
    core/randomgenerator.cpp

HEADERS += app/libs.h \
    core/questionreader.h \
    core/question.h \
    learningstrategies/teacher.h \
    learningstrategies/naiveteacher.h \
    learningstrategies/simpleteacher.h \
    learningstrategies/byrepetitionteacher.h \
    app/dbmigrator.h \
    core/scorerepository.h \
    core/roulettewheelselector.h \
    core/randomgenerator.h
