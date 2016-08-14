#-------------------------------------------------
#
# Project created by QtCreator 2016-08-14T08:33:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DesignPattern
TEMPLATE = app


SOURCES += main.cpp\
        FileReader.cpp\
        Pattern.cpp \
        GraphicModel.cpp \
    View.cpp \
    ViewPattern.cpp \
    ViewAnswers.cpp

HEADERS  +=\
            FileReader.hpp\
            Pattern.hpp \
            GraphicModel.hpp \
    View.hpp \
    ViewPattern.hpp \
    ViewAnswers.hpp
