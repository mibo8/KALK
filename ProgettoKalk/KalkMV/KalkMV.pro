#-------------------------------------------------
#
# Project created by QtCreator 2018-08-24T15:44:57
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = KalkMV
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++0x

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
    View/mainwindow.cpp \
    Model/figura.cpp \
    Model/punto.cpp \
    Model/cerchio.cpp \
    Model/segmento.cpp \
    Model/poligono.cpp \
    Model/rettangolo.cpp \
    Model/triangolo.cpp \
    View/scenapianocartesiano.cpp \
    Model/vettorefigure.cpp \
    View/figuralistitem.cpp \
    View/menucalcoli.cpp \
    View/risultato.cpp \
    View/rettangolografico.cpp \
    View/triangolografico.cpp \
    View/cerchiografico.cpp \
    View/segmentografico.cpp \
    View/err_campi_vuoti.cpp

HEADERS += \
    View/mainwindow.h \
    Model/figura.h \
    Model/punto.h \
    Model/cerchio.h \
    Model/segmento.h \
    Model/poligono.h \
    Model/rettangolo.h \
    Model/triangolo.h \
    View/scenapianocartesiano.h \
    Model/vettorefigure.h \
    View/figuralistitem.h \
    View/menucalcoli.h \
    View/risultato.h \
    View/cerchiografico.h \
    View/rettangolografico.h \
    View/triangolografico.h \
    View/segmentografico.h \
    View/err_campi_vuoti.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    View/mainwindow.ui \
    View/aggiungifigura.ui
