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

INCLUDEPATH += include/

HEADERS = \
        include/qwt_mml_document.h \
        include/qwt_mml_entity_table.h \
        include/formulaview.h \
        include/qwt_mml_global.h

SOURCES = \
        src/qwt_mml_document.cpp \
        src/qwt_mml_entity_table.cpp \
        src/formulaview.cpp
