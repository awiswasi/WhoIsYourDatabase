QT       += core gui
QT      += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    display.cpp \
    edit_cities.cpp \
    edit_food.cpp \
    function.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    trip.cpp \
    triptake.cpp

HEADERS += \
    admin.h \
    db.h \
    display.h \
    edit_cities.h \
    edit_food.h \
    login.h \
    mainwindow.h \
    trip.h \
    triptake.h

FORMS += \
    admin.ui \
    display.ui \
    edit_cities.ui \
    edit_food.ui \
    login.ui \
    mainwindow.ui \
    trip.ui \
    triptake.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
