#ifndef _QWT_MML_DOCUMENT_H_
#define _QWT_MML_DOCUMENT_H_

#include <QtGlobal>

#include <QColor>
#include <QString>
#include <QSize>
#include <QMap>

#include "global.h"

class QPainter;
class QPointF;
class QDomNode;

typedef QMap<QString, QString> QwtMmlAttributeMap;

class QwtMmlDocument;

class QwtMmlNode;

struct QwtMml
{
    enum NodeType
    {
        NoNode = 0, MiNode, MnNode, MfracNode, MrowNode, MsqrtNode,
        MrootNode, MsupNode, MsubNode, MsubsupNode, MoNode,
        MstyleNode, TextNode, MphantomNode, MfencedNode,
        MtableNode, MtrNode, MtdNode, MoverNode, MunderNode,
        MunderoverNode, MerrorNode, MtextNode, MpaddedNode,
        MspaceNode, MalignMarkNode, UnknownNode
    };

    enum MathVariant
    {
        NormalMV       = 0x0000,
        BoldMV         = 0x0001,
        ItalicMV       = 0x0002,
        DoubleStruckMV = 0x0004,
        ScriptMV       = 0x0008,
        FrakturMV      = 0x0010,
        SansSerifMV    = 0x0020,
        MonospaceMV    = 0x0040
    };

    enum FormType { PrefixForm, InfixForm, PostfixForm };
    enum ColAlign { ColAlignLeft, ColAlignCenter, ColAlignRight };
    enum RowAlign { RowAlignTop, RowAlignCenter, RowAlignBottom,
                    RowAlignAxis, RowAlignBaseline
                  };
    enum FrameType { FrameNone, FrameSolid, FrameDashed };

    struct FrameSpacing
    {
        FrameSpacing( qreal hor = 0.0, qreal ver = 0.0 )
            : m_hor( hor ), m_ver( ver ) {}
        qreal m_hor, m_ver;
    };
};

class QTMML_EXPORT QwtMmlDocument : public QwtMml
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

    void clear();

    bool setContent( const QString &text, QString *errorMsg = 0,
                     int *errorLine = 0, int *errorColumn = 0 );
    void paint( QPainter *painter, const QPointF &pos ) const;
    void dump() const;
    QSizeF size() const;
    void layout();

    QString fontName( QwtMmlDocument::MmlFont type ) const;
    void setFontName( QwtMmlDocument::MmlFont type, const QString &name );

    qreal baseFontPointSize() const;
    void setBaseFontPointSize( qreal size );

    QColor foregroundColor() const;
    void setForegroundColor( const QColor &color );

    QColor backgroundColor() const;
    void setBackgroundColor( const QColor &color );

    bool drawFrames() const;
    void setDrawFrames( const bool &drawFrames );

private:
    void _dump( const QwtMmlNode *node, const QString &indent ) const;
    bool insertChild( QwtMmlNode *parent, QwtMmlNode *new_node,
                      QString *errorMsg );

    QwtMmlNode *domToMml( const QDomNode &dom_node, bool *ok,
                          QString *errorMsg );
    QwtMmlNode *createNode( NodeType type,
                            const QwtMmlAttributeMap &mml_attr,
                            const QString &mml_value, QString *errorMsg );
    QwtMmlNode *createImplicitMrowNode( const QDomNode &dom_node, bool *ok,
                                     QString *errorMsg );

    void insertOperator( QwtMmlNode *node, const QString &text );

    QwtMmlNode *m_root_node;

    QString m_normal_font_name;
    QString m_fraktur_font_name;
    QString m_sans_serif_font_name;
    QString m_script_font_name;
    QString m_monospace_font_name;
    QString m_doublestruck_font_name;
    qreal m_base_font_point_size;
    QColor m_foreground_color;
    QColor m_background_color;

    bool m_draw_frames;
};

#endif
