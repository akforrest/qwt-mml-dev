#ifndef _QWT_MML_DOCUMENT_H_
#define _QWT_MML_DOCUMENT_H_

#include <QtGlobal>

#include <QColor>
#include <QString>
#include <QSize>
#include <QMap>

#include "qtmml/core/global.h"

#include "qtmml/core/types.h"

class QPainter;
class QPointF;
class QDomNode;

typedef QMap<QString, QString> QwtMmlAttributeMap;

class QwtMmlDocument;

class QwtMmlNode;

class QTMML_EXPORT QwtMmlDocument
{
public:
    enum MmlFont
    {
        NormalFont,
        FrakturFont,
        SansSerifFont,
        ScriptFont,
        MonospaceFont,
        DoublestruckFont
    };

    QwtMmlDocument();
    ~QwtMmlDocument();

    void            clear();

    bool            setContent(const QString & text,
                               QString * errorMsg = 0,
                               int * errorLine = 0,
                               int * errorColumn = 0);

    void            paint(QPainter * painter, const QPointF & pos) const;

    void            debugPrint() const;

    QSizeF          size() const;

    void            layout();

    QString         fontName(QwtMmlDocument::MmlFont type) const;
    void            setFontName(QwtMmlDocument::MmlFont type, const QString & name);

    qreal           baseFontPointSize() const;
    void            setBaseFontPointSize(const qreal size);

    QColor          foregroundColor() const;
    void            setForegroundColor(const QColor & color);

    QColor          backgroundColor() const;
    void            setBackgroundColor(const QColor & color);

    bool            drawFrames() const;
    void            setDrawFrames(const bool drawFrames);

private:

    void            _debugPrint(const QwtMmlNode * node, const QString & indent) const;

    bool            insertChild(QwtMmlNode * parent, QwtMmlNode * new_node, QString * errorMsg);

    QwtMmlNode *    domToMml(const QDomNode & dom_node, bool * ok, QString * errorMsg);
    QwtMmlNode *    createNode(QwtMml::NodeType type, const QwtMmlAttributeMap & mml_attr, const QString & mml_value, QString * errorMsg);
    QwtMmlNode *    createImplicitMrowNode(const QDomNode & dom_node, bool * ok, QString * errorMsg);

    void            insertOperator(QwtMmlNode * node, const QString & text);

    QwtMmlNode *    m_root_node;

    QString         m_normal_font_name;
    QString         m_fraktur_font_name;
    QString         m_sans_serif_font_name;
    QString         m_script_font_name;
    QString         m_monospace_font_name;
    QString         m_doublestruck_font_name;

    qreal           m_base_font_point_size;

    QColor          m_foreground_color;
    QColor          m_background_color;

    bool            m_draw_frames;
};

#endif
