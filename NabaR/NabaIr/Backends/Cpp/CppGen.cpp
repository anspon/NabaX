#include "NabaIrPch.h"
#include "Backends/CodeStreamer.h"
#include "Module.h"
#include "Function.h"
#include "TranslationUnit.h"
#include "Parameter.h"
#include "Type.h"
#include "Block.h"
#include "Variable.h"
#include "Instruction.h"
#include "Literal.h"

namespace NabaIr
{
namespace Backends
{

namespace CppGen
{
//--------------------------------------------------------------------------------------------------
static void StreamBlock(
    Tk::Sp<const CBlock> block,
    CStream& stream
    );

//--------------------------------------------------------------------------------------------------
static void StreamLiteral(
    Tk::Sp<const CLiteral> literal,
    CStream& stream
    )
{
    switch( literal->NativeType() )
    {
        case ntInt32:
        {
            stream.Stream() << "int32_t(" << literal->Int32() << ")";
            break;
        }
        case ntInt64:
        {
            stream.Stream() << "int64_t(" << literal->Int64() << ")";
            break;
        }
    }
}
//--------------------------------------------------------------------------------------------------
static void StreamInstruction(
    Tk::Sp<const CInstruction> instruction,
    CStream& stream
    )
{
    switch(instruction->InstructionType() )
    {
        case itAssignLiteral:
        {
            stream << instruction->LhsVariable()->Name() << " = ";
            StreamLiteral(instruction->RhsLiteral(), stream );
            stream << ";" << CStream::CEndLine();
            break;
        }
        case itIncrementLiteral:
        {
            stream << instruction->LhsVariable()->Name() << " += ";
            StreamLiteral(instruction->RhsLiteral(), stream );
            stream << ";" << CStream::CEndLine();
            break;
        }
        case itZeroVariable:
        {
            stream << instruction->LhsVariable()->Name() << " = 0";
            stream << ";" << CStream::CEndLine();
            break;
        }
        case itAssignVariable:
        {
            stream << instruction->LhsVariable()->Name() << " = " << instruction->RhsVariable()->Name();
            stream << ";" << CStream::CEndLine();
            break;
        }
        case itIncrementVariable:
        {
            stream << instruction->LhsVariable()->Name() << " += " << instruction->RhsVariable()->Name();
            stream << ";" << CStream::CEndLine();
            break;
        }
        case itCallFunction:
        {
            stream << instruction->Function()->Name() << "(";
            for( auto it  = instruction->FunctionParameters().begin(); it != instruction->FunctionParameters().end(); it++ )
            {
                if( it != instruction->FunctionParameters().begin() )
                {
                    stream << ", ";
                }
                stream << (*it)->Name();
            }
            stream << ");" << CStream::CEndLine();
            break;
        }
        case itWhile:
        {
            stream << CStream::CEndLine();
            stream << "while( " << instruction->LhsVariable()->Name() << " )"  << CStream::CEndLine();
            StreamBlock(instruction->Block(), stream );
            stream << CStream::CEndLine();
            break;
        }
    }
}
//--------------------------------------------------------------------------------------------------
static void StreamNativeType(
    eNativeType nativeType,
    CStream& stream
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
//--------------------------------------------------------------------------------------------------
static void StreamBlock(
    Tk::Sp<const CBlock> block,
    CStream& stream
    )
{
    stream << "{" << CStream::CEndLine();
    {
        CIndenter indent(stream, 1);

        for( Tk::Sp<const CVariable> variable : block->Variables() )
        {
            StreamNativeType(variable->DataType()->NativeType(), stream);
            stream << " " << variable->Name() << ";" << CStream::CEndLine();
        }
        for( Tk::Sp<const CInstruction> instruction : block->Instructions() )
        {
            StreamInstruction(instruction, stream);
        }
    }
    stream << "}" << CStream::CEndLine();
}
//--------------------------------------------------------------------------------------------------
static void StreamParameter(
    Tk::Sp<const CParameter> parameter,
    CStream& stream
    )
{
    switch( parameter->ParameterType() )
    {
        case ptIn : 
        {
            stream << "const ";
            break;
        }
        case ptOut:
        case ptInOut:
        {
            break;
        }
    }
    StreamNativeType(parameter->Variable()->DataType()->NativeType(), stream);
    stream << "& " << parameter->Variable()->Name();
}
//--------------------------------------------------------------------------------------------------
static void StreamFunction(
    Tk::Sp<const CFunction> function,
    CStream& stream
    )
{
    stream << "void " << function->Name() << "(";

    {
        CIndenter indent(stream, 1);
        for( auto it = function->Parameters().begin(); it != function->Parameters().end(); it++ )
        {
            if( it != function->Parameters().begin() )
            {
                stream << ", " << CStream::CEndLine();
            }
            stream << CStream::CEndLine();
            StreamParameter(*it, stream);
        }

        stream << CStream::CEndLine() << ")" << CStream::CEndLine();
    }
    StreamBlock(function->Block(), stream);

    stream << "//--------------------------------------------------------------------------------------------------";
    stream << CStream::CEndLine();
}
//--------------------------------------------------------------------------------------------------
void Stream(
    Tk::Sp<const CModule> module, 
    CStream& stream
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
    CStream& streamer
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
    CStream& streamer
    )const
{
    for( Tk::Sp<const CBlockPart> block : m_blockParts )
    {
        streamer << block;
    }
}
//--------------------------------------------------------------------------------------------------
void CDouble::MakeCpp(
    CStream & streamer
    ) const
{
    streamer.CoreStream() << m_value;
}

//--------------------------------------------------------------------------------------------------
void CFunctionDeclaration::MakeCpp(
    CStream& streamer
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
    CStream& streamer
    ) const
{
    streamer << m_type << " " << m_id;
}
    void 
        MakeCpp(
            CStream& streamer
            )const override;


                void 
        MakeCpp(
            CStream& streamer
            )const;

//--------------------------------------------------------------------------------------------------
void CInteger64::MakeCpp( 
    CStream& streamer 
    )const
{
    streamer.CoreStream() << m_value;
}

//--------------------------------------------------------------------------------------------------
void CNode::MakeCpp(
    CStream& streamer
    )const
{
}

//--------------------------------------------------------------------------------------------------
void CIdentifier::MakeCpp(
    CStream& streamer
    )const
{
    streamer << m_name;
}

//--------------------------------------------------------------------------------------------------
CStream& operator<<(CStream& streamer, Tk::Sp<const CNode> node )
{
    node->MakeCpp(streamer);
    return streamer;
}
//--------------------------------------------------------------------------------------------------
void CAssignment::MakeCpp(
    CStream& streamer
    ) const
{
    streamer << m_lhs << "=" << m_rhs << ";" << CStream::endl;
}
//--------------------------------------------------------------------------------------------------
void CStruct::MakeCpp(
    CStream& streamer
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
    CStream& streamer
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
CStream& operator<<(CStream& streamer, Tk::Sp<const CNode> node );
//--------------------------------------------------------------------------------------------------
void CInteger32::MakeCpp(
    CStream& streamer
    ) const
{
    streamer.CoreStream() << m_value;
}
//--------------------------------------------------------------------------------------------------
void CExpressionStatement::MakeCpp(
    CStream& streamer
    ) const
{
    m_expression->MakeCpp(streamer);
}
*/