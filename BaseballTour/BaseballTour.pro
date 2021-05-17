QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ballparkdb.cpp \
    customtrip.cpp \
    dbmanager.cpp \
    dfsbfs.cpp \
    distancesdb.cpp \
    editteam.cpp \
    graph.cpp \
    graphmst.cpp \
    addsouvenir.cpp \
    logindialog.cpp \
    main.cpp \
    mainwindow.cpp \
    planyourtrip.cpp \
    showmst.cpp \
    takeyourtrip.cpp \
    tripplan.cpp \
    triptake.cpp \
    triptake_old.cpp

HEADERS += \
    ballparkdb.h \
    customtrip.h \
    dbmanager.h \
    dfsbfs.h \
    distancesdb.h \
    editteam.h \
    graph.h \
    graphmst.h \
    planyourtrip.h \
    showmst.h \
    stadiumstructs.h \
    addsouvenir.h \
    logindialog.h \
    mainwindow.h \
    takeyourtrip.h \
    tripplan.h \
    triptake.h \
    triptake_old.h

FORMS += \
    addsouvenir.ui \
    customtrip.ui \
    dfsbfs.ui \
    editteam.ui \
    logindialog.ui \
    mainwindow.ui \
    graph.ui \
    planyourtrip.ui \
    showmst.ui \
    takeyourtrip.ui \
    tripplan.ui \
    triptake.ui \
    triptake_old.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    team.qrc
