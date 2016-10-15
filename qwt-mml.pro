TEMPLATE = lib
TARGET   = qtmml

CONFIG += qt
CONFIG += no_keywords
CONFIG += warn_on

QT += xml
QT += widgets

MOC_DIR      = moc
OBJECTS_DIR  = obj

DEFINES += QWT_MML_BUILD

INCLUDEPATH += include

HEADERS = \
        include/qtmml/formulaview.h \
    include/qtmml/formulaviewwidget.h \
    include/qtmml/document.h \
    include/qtmml/entity_table.h \
    include/qtmml/global.h

SOURCES = \
        src/formulaview.cpp \
    include/qtmml/formulaviewwidget.cpp \
    src/document.cpp \
    src/entity_table.cpp
