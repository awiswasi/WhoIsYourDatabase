QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ballparkdb.cpp \
    dbmanager.cpp \
    distancesdb.cpp \
    graph.cpp \
    graphmst.cpp \
    addsouvenir.cpp \
    logindialog.cpp \
    main.cpp \
    mainwindow.cpp \
    tripplan.cpp \
    triptake.cpp

HEADERS += \
    ballparkdb.h \
    dbmanager.h \
    distancesdb.h \
    graph.h \
    graphmst.h \
    stadiumstructs.h \
    addsouvenir.h \
    logindialog.h \
    mainwindow.h \
    tripplan.h \
    triptake.h

FORMS += \
    addsouvenir.ui \
    logindialog.ui \
    mainwindow.ui \
    graph.ui \
    tripplan.ui \
    triptake.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    team.qrc
