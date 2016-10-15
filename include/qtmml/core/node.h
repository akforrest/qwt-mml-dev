#ifndef _QTMML_NODE_H
#define _QTMML_NODE_H

#include "qtmml/core/document.h"

#include <QRectF>
#include <QFont>

class QwtMmlNode
{
    friend class QwtMmlDocument;

public:

    QwtMmlNode( QwtMml::NodeType type, QwtMmlDocument *document,
                const QwtMmlAttributeMap &attribute_map );
    virtual ~QwtMmlNode();

    // Mml stuff
    QwtMml::NodeType nodeType() const { return m_node_type; }

    virtual QString toStr() const;

    void setRelOrigin( const QPointF &rel_origin );

    void stretchTo( const QRectF &rect );
    QPointF devicePoint( const QPointF &p ) const;

    QRectF myRect() const { return m_my_rect; }
    virtual void setMyRect( const QRectF &rect ) { m_my_rect = rect; }
    void updateMyRect();

    QRectF parentRect() const;
    virtual QRectF deviceRect() const;

    virtual void stretch();
    virtual void layout();
    virtual void paint( QPainter *painter, qreal x_scaling, qreal y_scaling );

    qreal basePos() const;

    qreal em() const;
    qreal ex() const;

    QString explicitAttribute( const QString &name, const QString &def = QString::null ) const;
    QString inheritAttributeFromMrow( const QString &name, const QString &def = QString::null ) const;

    virtual QFont font() const;
    virtual QColor color() const;
    virtual QColor background() const;
    virtual int scriptlevel( const QwtMmlNode *child = 0 ) const;

    // Node stuff
    QwtMmlNode *parent() const { return m_parent; }
    QwtMmlNode *firstChild() const { return m_first_child; }
    QwtMmlNode *nextSibling() const { return m_next_sibling; }
    QwtMmlNode *previousSibling() const { return m_previous_sibling; }
    QwtMmlNode *lastSibling() const;
    QwtMmlNode *firstSibling() const;
    bool isLastSibling() const { return m_next_sibling == 0; }
    bool isFirstSibling() const { return m_previous_sibling == 0; }
    bool hasChildNodes() const { return m_first_child != 0; }

protected:
    virtual void layoutSymbol();
    virtual void paintSymbol( QPainter *painter, qreal, qreal ) const;
    virtual QRectF symbolRect() const { return QRectF( 0.0, 0.0, 0.0, 0.0 ); }

    QwtMmlNode *parentWithExplicitAttribute( const QString &name, QwtMml::NodeType type = QwtMml::NoNode );
    qreal interpretSpacing( const QString &value, bool *ok ) const;

    qreal lineWidth() const;

private:

    QwtMmlAttributeMap m_attribute_map;
    bool m_stretched;
    QRectF m_my_rect, m_parent_rect;
    QPointF m_rel_origin;

    QwtMml::NodeType m_node_type;
    QwtMmlDocument *m_document;

    QwtMmlNode *m_parent,
               *m_first_child,
               *m_next_sibling,
               *m_previous_sibling;
};

#endif // _QTMML_NODE_H
