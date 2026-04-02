QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    adminwindow.cpp \
    guestwindow.cpp \
    hotelsystem.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    registerwindow.cpp \
    staffwindow.cpp

HEADERS += \
    adminwindow.h \
    guestwindow.h \
    hotelsystem.h \
    loginwindow.h \
    mainwindow.h \
    registerwindow.h \
    staffwindow.h

FORMS += \
    adminwindow.ui

RESOURCES += \
    resources.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
