#-------------------------------------------------
#
# Project created by QtCreator 2017-05-10T15:17:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mytrainer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
    QtLogin.cpp \
    QtRegister.cpp \
    QtAddPlan.cpp \
    QtAdmin.cpp \
    QtStartSelling.cpp \
    QtSystemLog.cpp \
    QtStopSelling.cpp \
    QtQueryUser.cpp \
    QtMyOrder.cpp \
    QtModifyInformation.cpp \
    QtCancelPlan.cpp \
    QtBookTicket.cpp \
    QtGeneralUser.cpp \
    QtModifyPlan.cpp \
    Train.cpp \
    TrainSystem.cpp \
    User.cpp

HEADERS  += \
    QtLogin.h \
    QtRegister.h \
    QtAddPlan.h \
    QtAdmin.h \
    QtStartSelling.h \
    QtSystemLog.h \
    QtStopSelling.h \
    QtQueryUser.h \
    QtMyOrder.h \
    QtModifyInformation.h \
    QtCancelPlan.h \
    QtBookTicket.h \
    QtGeneralUser.h \
    QtModifyPlan.h \
    binfstream.hpp \
    Date.hpp \
    exceptions.hpp \
    Log.hpp \
    map.hpp \
    SHA512.hpp \
    Station.hpp \
    Ticket.hpp \
    Time.hpp \
    Train.h \
    TrainSystem.h \
    User.h \
    utility.hpp \
    vector.hpp \
    Transfer.hpp

FORMS    += \
    QtLogin.ui \
    QtRegister.ui \
    QtAddPlan.ui \
    QtAdmin.ui \
    QtStartSelling.ui \
    QtSystemLog.ui \
    QtStopSelling.ui \
    QtQueryUser.ui \
    QtMyOrder.ui \
    QtModifyInformation.ui \
    QtCancelPlan.ui \
    QtBookTicket.ui \
    QtGeneralUser.ui \
    QtModifyPlan.ui

CONFIG   += c++11
