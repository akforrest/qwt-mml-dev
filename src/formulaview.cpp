#include "qtmml/formulaview.h"
#include "qtmml/document.h"

#include <QPainter>

#include <QDebug>

QtMml::FormulaView::FormulaView()
    :
    d_fontSize(8),
    d_transformation(true),
    d_scale(false),
    d_rotation(0),
    d_drawFrames(false),
    d_colors(false)
{
}

QString QtMml::FormulaView::formula() const
{
    return d_formula;
}

void QtMml::FormulaView::setFormula(const QString & formula)
{
    d_formula = formula;
}

void QtMml::FormulaView::setFontSize(const qreal fontSize)
{
    d_fontSize = fontSize;
}

void QtMml::FormulaView::setTransformation(const bool transformation)
{
    d_transformation = transformation;
}

void QtMml::FormulaView::setScale(const bool scale)
{
    d_scale = scale;
}

void QtMml::FormulaView::setRotation(const qreal rotation)
{
    d_rotation = rotation;
}

void QtMml::FormulaView::setDrawFrames(const bool drawFrames)
{
    d_drawFrames = drawFrames;
}

void QtMml::FormulaView::setColors(const bool colors)
{
    d_colors = colors;
}

void QtMml::FormulaView::renderFormula(QPainter * painter, const QPointF & center) const
{
    QwtMathMLDocument doc;
    doc.setContent(d_formula);
    if (d_colors)
    {
        doc.setBackgroundColor(Qt::darkCyan);
        doc.setForegroundColor(Qt::yellow);
    }
    else
    {
        doc.setBackgroundColor(Qt::white);
        doc.setForegroundColor(Qt::black);
    }

    doc.setBaseFontPointSize(d_fontSize);

    doc.setDrawFrames(d_drawFrames);

    QRectF docRect;
    docRect.setSize(doc.size());
    docRect.moveCenter(center);

    if (d_transformation)
    {
        const double scaleF = d_scale ? 2.0 : 1.0;

        painter->save();

        painter->translate(docRect.center());
        painter->rotate(d_rotation);
        painter->scale(scaleF, scaleF);
        painter->translate(docRect.topLeft() - docRect.center());
        doc.paint(painter, QPointF(0.0, 0.0));

        painter->restore();
    }
    else
    {
        doc.paint(painter, docRect.topLeft());
    }
}
