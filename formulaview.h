#ifndef _FORMULA_VIEW_H_
#define _FORMULA_VIEW_H_

#include <QWidget>

#include "qwt_mml_global.h"

class QPainter;

class QWT_EXPORT FormulaView : public QWidget
{
    Q_OBJECT

public:

    FormulaView( QWidget *parent = NULL );

    QString formula() const;

public Q_SLOTS:
    void setFormula( const QString & );
    void setFontSize( const qreal & );
    void setTransformation( const bool &transformation );
    void setScale( const bool &scale );
    void setRotation( const qreal & );
    void setDrawFrames( const bool &drawFrames );
    void setColors( const bool &colors );

protected:
    virtual void paintEvent( QPaintEvent * );

private:
    void renderFormula( QPainter * ) const;

private:
    QString d_formula;
    qreal d_fontSize;
    bool d_transformation;
    bool d_scale;
    qreal d_rotation;
    bool d_drawFrames;
    bool d_colors;
};

#endif
