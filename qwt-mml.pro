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

HEADERS = \
	qwt_mml_document.h \
	qwt_mml_entity_table.h \
	formulaview.h \
        qwt_mml_global.h

SOURCES = \
	qwt_mml_document.cpp \
	qwt_mml_entity_table.cpp \
	formulaview.cpp
