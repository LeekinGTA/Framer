QT       += core gui widgets
CONFIG += c++14
TARGET = Framer
TEMPLATE = app


SOURCES += src/main.cpp\
        src/mainwindow.cpp \
    src/aboutdialog.cpp

HEADERS  += src/mainwindow.h \
    src/aboutdialog.h \
    src/stdafx.h

FORMS +=\
    ui/main_window.ui \
    src/aboutdialog.ui

