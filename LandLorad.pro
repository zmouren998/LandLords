QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    card.cpp \
    cardpanel.cpp \
<<<<<<< HEAD
    cards.cpp \
=======
>>>>>>> 0f463c2428bf133bff15332ce56532b8fbbc8355
    main.cpp \
    gamepanel.cpp \
    player.cpp

HEADERS += \
    card.h \
    cardpanel.h \
<<<<<<< HEAD
    cards.h \
=======
>>>>>>> 0f463c2428bf133bff15332ce56532b8fbbc8355
    gamepanel.h \
    player.h

FORMS += \
    gamepanel.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
