#-------------------------------------------------
#
# Project created by QtCreator 2018-11-21T18:48:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Game4InARow
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    gamefield.cpp \
    field.cpp \
    circle.cpp \
    aicircle.cpp \
    usercircle.cpp \
    singleplayerfield.cpp \
    twoplayersfield.cpp \
    controller.cpp \
    scene.cpp

HEADERS += \
        mainwindow.h \
    gamefield.h \
    field.h \
    circle.h \
    aicircle.h \
    usercircle.h \
    singleplayerfield.h \
    twoplayersfield.h \
    controller.h \
    constanter.h \
    scene.h

FORMS += \
        mainwindow.ui \
    gamefield.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

win32: LIBS += -L$$PWD/./ -lBox2D

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/./Box2D.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/./libBox2D.a
