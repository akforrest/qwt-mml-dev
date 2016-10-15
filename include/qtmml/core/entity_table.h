#ifndef _QWT_MML_ENTITY_TABLE_H_
#define _QWT_MML_ENTITY_TABLE_H_

#include <QtGlobal>

#include <QString>

#include "global.h"

class QTMML_EXPORT QwtMMLEntityTable
{

public:

    struct Spec
    {
        const char *name;
        const char *value;
    };

    static QString entities();
    static const Spec * search(const QString &value, const Spec * from = 0);
};

#endif





