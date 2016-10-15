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
        include/qtmml/core/document.h \
        include/qtmml/core/entity_table.h \
        include/qtmml/core/global.h \
    include/qtmml/core/types.h

SOURCES = \
        src/formulaview.cpp \
        src/formulaviewwidget.cpp \
        src/core/document.cpp \
        src/core/entity_table.cpp
