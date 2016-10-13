#ifndef _QWT_MML_ENTITY_TABLE_H_
#define _QWT_MML_ENTITY_TABLE_H_

#include <QtGlobal>

#include <QString>

#include "qwt_mml_global.h"

class QWT_EXPORT QwtMMLEntityTable
{
public:
    struct Spec
    {
        const char *name;
        const char *value;
    };

    QString entities() const;
    const Spec *search( const QString &value, const Spec *from = 0 ) const;
};

#endif





