#-------------------------------------------------
#
# Project created by QtCreator 2016-10-30T19:59:33
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = supermega
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    loginform.cpp \
    workerform.cpp \
    departform.cpp \
    visitform.cpp \
    inforec.cpp

HEADERS  += mainwindow.h \
    loginform.h \
    workerform.h \
    departform.h \
    visitform.h \
    inforec.h

FORMS    += mainwindow.ui \
    loginform.ui \
    workerform.ui \
    departform.ui \
    visitform.ui
