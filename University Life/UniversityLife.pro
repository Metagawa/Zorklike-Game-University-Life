QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 resources_big static

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Command.cpp \
    CommandWords.cpp \
    Parser.cpp \
    Room.cpp \
    ageable.cpp \
    character.cpp \
    event.cpp \
    eventlist.cpp \
    main.cpp \
    nameable.cpp \
    person.cpp \
    ramble.cpp \
    ramblelist.cpp \
    times.cpp \
    uniLife.cpp \
    uniZork.cpp

HEADERS += \
    Command.h \
    CommandWords.h \
    Parser.cpp \
    Room.h \
    ageable.h \
    character.h \
    event.h \
    eventlist.h \
    nameable.h \
    person.h \
    ramble.h \
    ramblelist.h \
    times.h \
    uniLife.h \
    uniZork.h

FORMS += \
    uniZork.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../resources/resources.qrc
win32: RC_ICONS = appico.ico
