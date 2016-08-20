QT += core
QT -= gui

CONFIG += c++11

TARGET = Tester
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Person.cpp \
    ChineseFamily.cpp

HEADERS += \
    Person.hpp \
    ChineseFamily.hpp

win32:INCLUDEPATH += ../../HighSpeedStorage/QJSON/qjson-master/include
unix:INCLUDEPATH += ../../HighSpeedStorage/qjson-linux-64/include

win32:LIBS += -lqjson-qt5
unix:LIBS += -lqjson-qt5
