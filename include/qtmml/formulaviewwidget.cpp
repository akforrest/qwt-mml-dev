#include "formulaviewwidget.h"

#include <QEvent>
#include <QPainter>
#include <QPaintEvent>

QtMml::FormulaViewWidget::FormulaViewWidget(QWidget * parent)
    : QWidget(parent),
      QtMml::FormulaView()
{
}

void QtMml::FormulaViewWidget::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);
    painter.setClipRegion(event->region());

    painter.fillRect(event->rect(), Qt::white);

    renderFormula(&painter, rect().center());
}
