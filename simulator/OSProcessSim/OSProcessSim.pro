QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    instructionitem.cpp \
    instructionoperation.cpp \
    main.cpp \
    mainwindow.cpp \
    processitem.cpp \
    resource.cpp \
    scheduler.cpp

HEADERS += \
    instructionitem.h \
    instructionoperation.h \
    mainwindow.h \
    processitem.h \
    resource.h \
    scheduler.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
