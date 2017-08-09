#include "NabaLPch.h"

#include "BinaryOperator.h"

#include "NabaIr/BlockBuilder.h"

namespace Ast
{
class CBlock;
class CExpression;
class CIdentifier;
class CVariableDeclaration;
class CFunctionParameter;
class CStructPart;
}
namespace NabaL
{
class CCompileError;
}


#include "Parser/Parser.hpp"

namespace Ast
{
//--------------------------------------------------------------------------------------------------
CBinaryOperator::CBinaryOperator(
    const CExpression* lhs, 
    int op, 
    const CExpression* rhs
    )
{
    m_lhs = Tk::AttachSp(lhs);
    m_op = op;
    m_rhs = Tk::AttachSp(rhs);
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const NabaIr::CVariable> CBinaryOperator::MakeExpressionIr(
    Tk::Sp<NabaIr::CTypeManager> typeManager,
    NabaIr::CBlockBuilder& blockBuilder
    ) const
{

    switch( m_op )
    {
        case TCGT:
        case TCGE:
        case TCLE:
        case TCLT:
        case TCNE:
        case TCEQ:
        {
            NabaIr::eBinaryBoolInstruction binaryBoolInstruction = NabaIr::bbiEqual;
            switch( m_op )
            {
                case TCGT: binaryBoolInstruction = NabaIr::bbiGreater;      break;
                case TCGE: binaryBoolInstruction = NabaIr::bbiGreaterEqual; break;
                case TCLE: binaryBoolInstruction = NabaIr::bbiLessEqual;    break;
                case TCLT: binaryBoolInstruction = NabaIr::bbiLess;         break;
                case TCNE: binaryBoolInstruction = NabaIr::bbiNotEqual;     break;
                case TCEQ: binaryBoolInstruction = NabaIr::bbiEqual;  break;
            }
            auto resultVariable = blockBuilder.AddLocalVariable("bool", "" );
            auto lhsVariable = m_lhs->MakeExpressionIr(typeManager, blockBuilder);
            auto rhsVariable = m_rhs->MakeExpressionIr(typeManager, blockBuilder);
            blockBuilder.AddBinaryOperationBoolResult(binaryBoolInstruction,resultVariable, lhsVariable, rhsVariable );
            return resultVariable;
            break;
        }
        case TPLUS:
        {
            break;
        }
        case TMINUS:
        {
            break;
        }
        case TMUL:
        {
            break;
        }
        case TDIV:
        {
            break;
        }
    }

    return Tk::Sp<const NabaIr::CVariable>();
}
}