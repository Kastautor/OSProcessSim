QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    configuration.cpp \
    instructionfactory.cpp \
    instructionitem.cpp \
    instructionload.cpp \
    instructionlock.cpp \
    instructionoperation.cpp \
    instructionsave.cpp \
    main.cpp \
    mainwindow.cpp \
    processitem.cpp \
    pugixml.cpp \
    resource.cpp \
    resourcescontroller.cpp \
    resourcesdatabase.cpp \
    scheduler.cpp \
    xmlmanager.cpp

HEADERS += \
    configuration.h \
    instructionfactory.h \
    instructionitem.h \
    instructionload.h \
    instructionlock.h \
    instructionoperation.h \
    instructionsave.h \
    mainwindow.h \
    processitem.h \
    pugiconfig.hpp \
    pugixml.hpp \
    resource.h \
    resourcescontroller.h \
    resourcesdatabase.h \
    scheduler.h \
    xmlmanager.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
