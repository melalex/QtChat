QT += core \
    network
QT -= gui

CONFIG += c++11

TARGET = ChatServer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    chatserver.cpp \
    client.cpp

HEADERS += \
    chatserver.h \
    client.h \
    ../../protocol.h
