#include "formulaview.h"
#include "qwt_mml_document.h"

#include <QEvent>
#include <QPainter>
#include <QPaintEvent>

#include <QDebug>

FormulaView::FormulaView(QWidget * parent):
    QWidget(parent),
    d_fontSize(8),
    d_transformation(true),
    d_scale(false),
    d_rotation(0),
    d_drawFrames(false),
    d_colors(false)
{
}

QString FormulaView::formula() const
{
    return d_formula;
}

void FormulaView::setFormula(const QString & formula)
{
    d_formula = formula;
    this->update();
}

void FormulaView::setFontSize(const qreal fontSize)
{
    d_fontSize = fontSize;
    this->update();
}

void FormulaView::setTransformation(const bool transformation)
{
    d_transformation = transformation;
    this->update();
}

void FormulaView::setScale(const bool scale)
{
    d_scale = scale;
    this->update();
}

void FormulaView::setRotation(const qreal rotation)
{
    d_rotation = rotation;
    this->update();
}

void FormulaView::setDrawFrames(const bool drawFrames)
{
    d_drawFrames = drawFrames;
    this->update();
}

void FormulaView::setColors(const bool colors)
{
    d_colors = colors;
    this->update();
}

void FormulaView::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);
    painter.setClipRegion(event->region());

    painter.fillRect(event->rect(), Qt::white);

    renderFormula(&painter);
}

void FormulaView::renderFormula(QPainter * painter) const
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
    docRect.moveCenter(rect().center());

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
