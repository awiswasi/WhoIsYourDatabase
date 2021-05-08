QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    function.cpp \
    customtrip.cpp \
    logindialog.cpp \
    main.cpp \
    mainwindow.cpp \
    tripplan.cpp \
    triptake.cpp

HEADERS += \
    dataBase.h \
    customtrip.h \
    logindialog.h \
    logindialog_copy.h \
    mainwindow.h \
    tripplan.h \
    triptake.h


FORMS += \
    logindialog.ui \
    mainwindow.ui \
    tripplan.ui \
    customtrip.ui \
    triptake.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
