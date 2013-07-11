#-------------------------------------------------
#
# Project created by QtCreator 2012-01-06T22:34:06
#
#-------------------------------------------------

QT       += core gui

TARGET = SdZSerial
TEMPLATE = app

SOURCES += main.cpp \
    fenetre.cpp

HEADERS  += \
    fenetre.h

FORMS    += \
    fenetre.ui

INCLUDEPATH += ./QextSerialPort

CONFIG(debug, debug|release):LIBS  += -lqextserialportd
else:LIBS  += -lqextserialport

