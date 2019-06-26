#-------------------------------------------------
#
# Project created by QtCreator 2019-05-14T09:11:35
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FreeMP3
TEMPLATE = app
RC_ICONS = logo.ico

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
    widget.cpp \
    main.cpp \
    audiowidget.cpp \
    mvwidget.cpp \
    downloadwidget.cpp

HEADERS += \
    widget.h \
    audiowidget.h \
    mvwidget.h \
    downloadwidget.h \
    common.h \
    ffmpeg.h

FORMS += \
        widget.ui \
    audiowidget.ui \
    mvwidget.ui \
    downloadwidget.ui


LIBS += -L$$PWD/../ffmpeg/lib/ -lavdevice
LIBS += -L$$PWD/../ffmpeg/lib/ -lavcodec
LIBS += -L$$PWD/../ffmpeg/lib/ -lavfilter
LIBS += -L$$PWD/../ffmpeg/lib/ -lavformat
LIBS += -L$$PWD/../ffmpeg/lib/ -lavutil
LIBS += -L$$PWD/../ffmpeg/lib/ -lpostproc
LIBS += -L$$PWD/../ffmpeg/lib/ -lswresample
LIBS += -L$$PWD/../ffmpeg/lib/ -lswscale

INCLUDEPATH += $$PWD/../ffmpeg/include


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES +=
