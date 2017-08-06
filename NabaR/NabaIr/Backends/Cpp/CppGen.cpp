#include "NabaIrPch.h"
#include "Backends/CodeStreamer.h"
#include "Module.h"
#include "Function.h"
#include "TranslationUnit.h"
#include "Parameter.h"
#include "Type.h"

namespace NabaIr
{
namespace Backends
{

namespace CppGen
{
//--------------------------------------------------------------------------------------------------
static void StreamNativeType(
    eNativeType nativeType,
    CCodeStreamer& stream
    )
{
    switch(nativeType)
    {
        case ntInt32:
        {
            stream << "int32_t";
            break;
        }
        case ntInt64:
        {
            stream << "int64_t";
            break;
        }
        case ntVoidPtr:
        {
            stream << "void*";
            break;
        }
    }
}
static void StreamParameter(
    Tk::Sp<const CParameter> parameter,
    CCodeStreamer& stream
    )
{
    StreamNativeType(parameter->Type()->NativeType(), stream);
    stream << " " << parameter->Name();
}
//--------------------------------------------------------------------------------------------------
static void StreamFunction(
    Tk::Sp<const CFunction> function,
    CCodeStreamer& stream
    )
{
    stream << "void " << function->Name() << "(" << CStream::CEndLine();

    {
        CIndenter indent(stream.Stream(), 1);
        for( auto it = function->Parameters().begin(); it != function->Parameters().end(); it++ )
        {
            if( it != function->Parameters().begin() )
            {
                stream << ", " << CStream::CEndLine();
            }
            StreamParameter(*it, stream);
        }

        stream << CStream::CEndLine() << ")" << CStream::CEndLine();
    }

    stream << "{";
    {
        CIndenter indent(stream.Stream(), 1);
    }
    stream << "}" << CStream::CEndLine();


}

void Stream(
    Tk::Sp<const CModule> module, 
    CCodeStreamer& stream
    )
{
    stream << "#include <stdint.h>" << CStream::CEndLine();

    for( Tk::Sp<const CTranslationUnit> unit : module->TranslationUnits() )
    {
        for( Tk::Sp<const CFunction> function : unit->Functions() )
        {
            StreamFunction(function, stream);
        }
    }
}

}
}
}
/*
//--------------------------------------------------------------------------------------------------
void CVariableDeclaration::MakeCpp(
    CCodeStreamer& streamer
    ) const
{
    streamer << m_type << " " << m_id;

    if( m_assignmentExpr )
    {
        streamer << " = " << m_assignmentExpr;
    }
    streamer << ";";
    streamer << CStream::endl;
}

//--------------------------------------------------------------------------------------------------
void CBlock::MakeCpp(
    CCodeStreamer& streamer
    )const
{
    for( Tk::Sp<const CBlockPart> block : m_blockParts )
    {
        streamer << block;
    }
}
//--------------------------------------------------------------------------------------------------
void CDouble::MakeCpp(
    CCodeStreamer & streamer
    ) const
{
    streamer.CoreStream() << m_value;
}

//--------------------------------------------------------------------------------------------------
void CFunctionDeclaration::MakeCpp(
    CCodeStreamer& streamer
    )const
{
    streamer << m_type << " " << m_id << "(" << StreamCollection(streamer, m_arguments, "," )  << ")" << CStream::endl;
    streamer << "{" << CStream::endl;
    {
        CIndenter indent(streamer.Stream(), 1 );
        streamer << m_block;
    }

    streamer << "}" << CStream::endl;
}
//--------------------------------------------------------------------------------------------------
void CFunctionParameter::MakeCpp(
    CCodeStreamer& streamer
    ) const
{
    streamer << m_type << " " << m_id;
}
    void 
        MakeCpp(
            CCodeStreamer& streamer
            )const override;


                void 
        MakeCpp(
            CCodeStreamer& streamer
            )const;

//--------------------------------------------------------------------------------------------------
void CInteger64::MakeCpp( 
    CCodeStreamer& streamer 
    )const
{
    streamer.CoreStream() << m_value;
}

//--------------------------------------------------------------------------------------------------
void CNode::MakeCpp(
    CCodeStreamer& streamer
    )const
{
}

//--------------------------------------------------------------------------------------------------
void CIdentifier::MakeCpp(
    CCodeStreamer& streamer
    )const
{
    streamer << m_name;
}

//--------------------------------------------------------------------------------------------------
CCodeStreamer& operator<<(CCodeStreamer& streamer, Tk::Sp<const CNode> node )
{
    node->MakeCpp(streamer);
    return streamer;
}
//--------------------------------------------------------------------------------------------------
void CAssignment::MakeCpp(
    CCodeStreamer& streamer
    ) const
{
    streamer << m_lhs << "=" << m_rhs << ";" << CStream::endl;
}
//--------------------------------------------------------------------------------------------------
void CStruct::MakeCpp(
    CCodeStreamer& streamer
    )const
{
    streamer.BeginStruct(m_name->m_name);
    {
        CIndenter indent(streamer.Stream(), 1);

        for( Tk::Sp<const CStructPart> structPart : m_parts )
        {
            streamer << structPart;
        }

    }

    streamer.EndStruct();
}
//--------------------------------------------------------------------------------------------------
void CStructVariable::MakeCpp(
    CCodeStreamer& streamer
        ) const
{
    streamer << m_type << CStream::endl;
    {
        CIndenter indent(streamer.Stream(), 1);
        streamer << m_id;
        
        if( m_assignmentExpr )
        {
            streamer << " = " << m_assignmentExpr;
        }
        streamer << ";";
    }
    streamer.Stream() << CStream::endl;
}
CCodeStreamer& operator<<(CCodeStreamer& streamer, Tk::Sp<const CNode> node );
//--------------------------------------------------------------------------------------------------
void CInteger32::MakeCpp(
    CCodeStreamer& streamer
    ) const
{
    streamer.CoreStream() << m_value;
}
//--------------------------------------------------------------------------------------------------
void CExpressionStatement::MakeCpp(
    CCodeStreamer& streamer
    ) const
{
    m_expression->MakeCpp(streamer);
}
*/