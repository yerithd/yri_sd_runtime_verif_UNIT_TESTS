# This file is a part of
# yri_sd_runtime_verif utility library !
#
# YR
#


TEMPLATE = app
TARGET = yri_monitor_test_1


CONFIG -= import_plugins
CONFIG -= disable-desktop
CONFIG += console
CONFIG += debug
CONFIG += testcase


QT += core
QT += sql
QT -= gui
QT += testlib

QMAKE_CXXFLAGS_RELEASE += --branch-probabilities -fprofile-arcs -ftest-coverage --coverage

# includes & libs
INCLUDEPATH += $$PWD/src 

LIBS += -L$$PWD/yri_sd_runtime_verif/lib -lyri_sd_runtime_verif

LIBS += -lgcov

DESTDIR = bin

# app sources
SOURCES += $$files($$PWD/src/*.cpp)
HEADERS += $$files($$PWD/src/*.hpp)
RESOURCES = yri_sd_runtime_verif_UNIT_TESTS.qrc




# temp dirs (unix)
unix{
    MOC_DIR = $$OUT_PWD/_generated
    OBJECTS_DIR = $$OUT_PWD/_generated
    UI_DIR = $$OUT_PWD/_generated
    RCC_DIR = $$OUT_PWD/_generated
}
