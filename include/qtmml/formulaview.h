#ifndef _QTMML_FORMULA_VIEW_H_
#define _QTMML_FORMULA_VIEW_H_

#include "core/global.h"

#include "qtmml/core/document.h"

#include <QtGlobal>
#include <QString>
#include <QPointF>
#include <QColor>

class QPainter;

namespace QtMml
{
    class QTMML_EXPORT FormulaView
    {
        public:

            FormulaView();

            QString     formula() const;

            void        setFormula(const QString & formula);

            void        setFontSize(const qreal fontSize);

            void        setTransformation(const bool transformation);
            void        setScale(const bool scale);
            void        setRotation(const qreal rotation);

            QColor      foregroundColor() const;
            void        setForegroundColor(const QColor & color);

            QColor      backgroundColor() const;
            void        setBackgroundColor(const QColor & color);

            void        setDrawFrames(const bool drawFrames);

        protected:

            void        renderFormula(QPainter * painter, const QPointF & center) const;

            QString     d_formula;
            qreal       d_fontSize;
            bool        d_transformation;
            bool        d_scale;
            qreal       d_rotation;
            bool        d_drawFrames;
            bool        d_colors;

            QwtMathMLDocument m_doc;
    };
}

#endif
