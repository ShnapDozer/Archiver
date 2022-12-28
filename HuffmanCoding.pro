QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HuffmanCoding
TEMPLATE = app


SOURCES += src/choose.cpp \
        src/common.cpp \
        src/decoding.cpp \
        src/encoding.cpp \
        src/huffman.cpp \
        src/main.cpp \
    src/fileEncodewidget.cpp

HEADERS += include/choose.h \
        include/common.h \
        include/decoding.h \
        include/encoding.h \
        include/huffman.h \
    include/fileEncodewidget.h

FORMS += forms/choose.ui \
        forms/decoding.ui \
        forms/encoding.ui \
    forms/fileEncodewidget.ui \
    forms/filedecodewidget.ui

RESOURCES += \
    res/resurses.qrc
