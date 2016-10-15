#ifndef _FORMULA_VIEW_H_
#define _FORMULA_VIEW_H_

#include <QWidget>

#include "core/global.h"
#include "formulaview.h"

class QPainter;

namespace QtMml
{
    class QTMML_EXPORT FormulaViewWidget : public QWidget,
            public QtMml::FormulaView
    {
        Q_OBJECT

    public:

        FormulaViewWidget(QWidget * parent = 0);

    protected:

        virtual void paintEvent(QPaintEvent * event) Q_DECL_OVERRIDE;
    };
}

#endif
