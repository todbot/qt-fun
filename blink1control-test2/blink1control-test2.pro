#-------------------------------------------------
#
# Project created by QtCreator 2013-04-28T13:11:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    blink1pattern.cpp \
    todgroupbox.cpp

HEADERS  += mainwindow.h \
    blink1pattern.h \
    todgroupbox.h

FORMS    += mainwindow.ui \
    dialog.ui \
    todgroupbox.ui

#unix|win32: LIBS += -L$$PWD/../../blink1/commandline -lBlink1
LIBS += -L$$PWD/../../blink1/commandline -lBlink1
INCLUDEPATH += $$PWD/../../blink1/commandline $$PWD/../../blink1/commandline/hidapi/hidapi $$PWD/../../blink1/hardware/firmware
DEPENDPATH += $$PWD/../../blink1/commandline

RESOURCES += \
    myresources.qrc


macx {
    MYAPPDIR=$$OUT_PWD/$${TARGET}.app/Contents/MacOS
    message( $$OUT_PWD )
    message( "MYAPPDIR = $$MYAPPDIR" )
    message( $$DESTDIR )
    message( $$DESTDIR_TARGET )
    message( $$OBJECTS_DIR )
    QMAKE_POST_LINK = cp -f $$PWD/../../blink1/commandline/libBlink1.dylib $$MYAPPDIR
}

# note to deploy must do commandline magic of:
# % macdeployqt test2.app -verbose=2
# % mv test2.app/Contents/MacOS/libBlink1.dylib test2.app/Contents/Frameworks

# FIXME: this lives outside the repo
include(../../qt/Qt-Color-Picker/color_widgets.pri)
