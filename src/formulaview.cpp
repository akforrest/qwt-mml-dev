
#include "qtmml/formulaview.h"

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
    m_doc.setBackgroundColor(Qt::transparent);
    m_doc.setForegroundColor(Qt::black);
}

QString QtMml::FormulaView::formula() const
{
    return d_formula;
}

void QtMml::FormulaView::setFormula(const QString & formula)
{
    d_formula = formula;
    m_doc.setContent(d_formula);
}

void QtMml::FormulaView::setFontSize(const qreal fontSize)
{
    d_fontSize = fontSize;
    m_doc.setBaseFontPointSize(d_fontSize);
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
    m_doc.setDrawFrames(d_drawFrames);
}

QColor QtMml::FormulaView::foregroundColor() const
{
    return m_doc.foregroundColor();
}

void QtMml::FormulaView::setForegroundColor(const QColor & color)
{
    m_doc.setForegroundColor(color);
}

QColor QtMml::FormulaView::backgroundColor() const
{
    return m_doc.backgroundColor();
}

void QtMml::FormulaView::setBackgroundColor(const QColor & color)
{
    m_doc.setBackgroundColor(color);
}

void QtMml::FormulaView::renderFormula(QPainter * painter, const QPointF & center) const
{
    QRectF docRect;
    docRect.setSize(m_doc.size());
    docRect.moveCenter(center);

    if (d_transformation)
    {
        const double scaleF = d_scale ? 2.0 : 1.0;

        painter->save();

        painter->translate(docRect.center());
        painter->rotate(d_rotation);
        painter->scale(scaleF, scaleF);
        painter->translate(docRect.topLeft() - docRect.center());
        m_doc.paint(painter, QPointF(0.0, 0.0));

        painter->restore();
    }
    else
    {
        m_doc.paint(painter, docRect.topLeft());
    }
}
