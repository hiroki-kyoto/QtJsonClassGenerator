QT += core
QT -= gui

CONFIG += c++11

TARGET = QtJsonClassGenerator
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

DISTFILES += \
    family.jcd \
    person.jcd
