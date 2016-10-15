#ifndef _QWT_MML_DOCUMENT_H_
#define _QWT_MML_DOCUMENT_H_

#include <QtGlobal>

#include <QColor>
#include <QString>
#include <QSize>

#include "global.h"

class QPainter;
class QPointF;

class QwtMmlDocument;

class QTMML_EXPORT QwtMathMLDocument
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

    QwtMathMLDocument();
    ~QwtMathMLDocument();

    void clear();

    bool setContent( const QString &text, QString *errorMsg = 0,
                     int *errorLine = 0, int *errorColumn = 0 );
    void paint( QPainter *, const QPointF &pos ) const;
    QSizeF size() const;

    QString fontName( MmlFont type ) const;
    void setFontName( MmlFont type, const QString &name );

    qreal baseFontPointSize() const;
    void setBaseFontPointSize( qreal size );

    QColor foregroundColor() const;
    void setForegroundColor( const QColor &color );

    QColor backgroundColor() const;
    void setBackgroundColor( const QColor &color );

    bool drawFrames() const;
    void setDrawFrames( bool );

private:
    QwtMmlDocument *m_doc;
};

#endif
