TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    logger.cpp \
    loggerimpl.cpp

HEADERS += \
    logger.h \
    loggerimpl.h
