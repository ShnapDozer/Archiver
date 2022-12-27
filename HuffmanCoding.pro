QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HuffmanCoding
TEMPLATE = app


SOURCES += src/choose.cpp \
        src/common.cpp \
        src/decoding.cpp \
        src/encoding.cpp \
        src/fileviewwidget.cpp \
        src/huffman.cpp \
        src/main.cpp

HEADERS += include/choose.h \
        include/common.h \
        include/decoding.h \
        include/encoding.h \
        include/fileviewwidget.h \
        include/huffman.h

FORMS += forms/choose.ui \
        forms/decoding.ui \
        forms/encoding.ui \
        forms/fileviewwidget.ui

RESOURCES += \
    res/resurses.qrc
