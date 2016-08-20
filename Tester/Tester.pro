QT += core
QT -= gui

CONFIG += c++11

TARGET = Tester
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    person.cpp \
    family.cpp

HEADERS += \
    person.h \
    family.h

win32:INCLUDEPATH += ../HighSpeedStorage/QJSON/qjson-master/include
unix:INCLUDEPATH += ../HighSpeedStorage/qjson-linux-64/include

win32:LIBS += -lqjson-qt5
unix:LIBS += -lqjson-qt5
