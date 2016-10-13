#ifndef _FORMULA_VIEW_H_
#define _FORMULA_VIEW_H_

#include <QWidget>

#include "qwt_mml_global.h"

class QPainter;

class QWT_EXPORT FormulaView : public QWidget
{
    Q_OBJECT

public:

    FormulaView(QWidget * parent = 0);

    QString formula() const;

public Q_SLOTS:

    void setFormula(const QString & formula);
    void setFontSize(const qreal fontSize);
    void setTransformation(const bool transformation);
    void setScale(const bool scale);
    void setRotation(const qreal rotation);
    void setDrawFrames(const bool drawFrames);
    void setColors(const bool colors);

protected:

    virtual void paintEvent(QPaintEvent * event) Q_DECL_OVERRIDE;

private:

    void renderFormula(QPainter * painter) const;

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
