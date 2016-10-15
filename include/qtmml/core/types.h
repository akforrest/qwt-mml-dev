#ifndef _QTMML_TYPES_H
#define _QTMML_TYPES_H

namespace QwtMml
{
    enum NodeType
    {
        NoNode = 0, MiNode, MnNode, MfracNode, MrowNode, MsqrtNode,
        MrootNode, MsupNode, MsubNode, MsubsupNode, MoNode,
        MstyleNode, TextNode, MphantomNode, MfencedNode,
        MtableNode, MtrNode, MtdNode, MoverNode, MunderNode,
        MunderoverNode, MerrorNode, MtextNode, MpaddedNode,
        MspaceNode, MalignMarkNode, UnknownNode
    };

    enum MathVariant
    {
        NormalMV       = 0x0000,
        BoldMV         = 0x0001,
        ItalicMV       = 0x0002,
        DoubleStruckMV = 0x0004,
        ScriptMV       = 0x0008,
        FrakturMV      = 0x0010,
        SansSerifMV    = 0x0020,
        MonospaceMV    = 0x0040
    };

    enum FormType { PrefixForm, InfixForm, PostfixForm };
    enum ColAlign { ColAlignLeft, ColAlignCenter, ColAlignRight };
    enum RowAlign { RowAlignTop, RowAlignCenter, RowAlignBottom,
                    RowAlignAxis, RowAlignBaseline
                  };
    enum FrameType { FrameNone, FrameSolid, FrameDashed };

    struct FrameSpacing
    {
        FrameSpacing( qreal hor = 0.0, qreal ver = 0.0 )
            : m_hor( hor ), m_ver( ver ) {}
        qreal m_hor, m_ver;
    };
}

#endif // _QTMML_TYPES_H
