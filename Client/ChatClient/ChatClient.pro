#-------------------------------------------------
#
# Project created by QtCreator 2016-08-31T15:32:57
#
#-------------------------------------------------

QT       += core gui\
            network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ChatClient
TEMPLATE = app


SOURCES += main.cpp\
    user.cpp \
    message.cpp \
    group.cpp \
    authorization.cpp \
    registration.cpp \
    contacts.cpp \
    addcontactdialog.cpp \
    chatdialog.cpp \
    groupchatdialog.cpp \
    connectionmenager.cpp \
    model.cpp \
    authorizationpresenter.cpp \
    registrationpresenter.cpp \
    addcontactdialogpresenter.cpp \
    chatdialogpresenter.cpp \
    contactspresenter.cpp \
    groupchatdialogpresenter.cpp \
    chatsmodel.cpp \
    groupchatsmodel.cpp \
    possiblecontactsmodel.cpp

HEADERS  += \
    user.h \
    message.h \
    group.h \
    authorization.h \
    registration.h \
    contacts.h \
    addcontactdialog.h \
    chatdialog.h \
    groupchatdialog.h \
    connectionmenager.h \
    model.h \
    authorizationpresenter.h \
    registrationpresenter.h \
    addcontactdialogpresenter.h \
    chatdialogpresenter.h \
    contactspresenter.h \
    groupchatdialogpresenter.h \
    chatsmodel.h \
    groupchatsmodel.h \
    possiblecontactsmodel.h \
    ../../protocol.h

FORMS    += \
    authorization.ui \
    registration.ui \
    contacts.ui \
    addcontactdialog.ui \
    chatdialog.ui \
    groupchatdialog.ui

RESOURCES += \
    resources/resources.qrc \
    resources/images/images.qrc
