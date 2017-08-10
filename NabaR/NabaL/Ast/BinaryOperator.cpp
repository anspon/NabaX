#include "NabaLPch.h"

#include "BinaryOperator.h"

#include "NabaIr/BlockBuilder.h"
#include "NabaIr/Variable.h"
#include "NabaIr/Type.h"

namespace Naba
{
namespace Lng
{
class CCompileError;
namespace Ast
{
class CBlock;
class CExpression;
class CIdentifier;
class CVariableDeclaration;
class CFunctionParameter;
class CStructPart;
}
}
}

#include "Parser/Parser.hpp"

namespace Naba
{
namespace Lng
{
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
Tk::Sp<const Ir::CVariable> CBinaryOperator::MakeExpressionIr(
    Tk::Sp<Ir::CTypeManager> typeManager,
    Ir::CBlockBuilder& blockBuilder
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
            Ir::eBinaryBoolInstruction binaryBoolInstruction = Ir::bbiEqual;
            switch( m_op )
            {
                case TCGT: binaryBoolInstruction = Ir::bbiGreater;      break;
                case TCGE: binaryBoolInstruction = Ir::bbiGreaterEqual; break;
                case TCLE: binaryBoolInstruction = Ir::bbiLessEqual;    break;
                case TCLT: binaryBoolInstruction = Ir::bbiLess;         break;
                case TCNE: binaryBoolInstruction = Ir::bbiNotEqual;     break;
                case TCEQ: binaryBoolInstruction = Ir::bbiEqual;  break;
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
            auto lhsVariable = m_lhs->MakeExpressionIr(typeManager, blockBuilder);
            auto rhsVariable = m_rhs->MakeExpressionIr(typeManager, blockBuilder);
            auto var  = blockBuilder.AddLocalVariable(lhsVariable->DataType()->TypeName(), "");
            blockBuilder.AssignVariable(var, lhsVariable);
            blockBuilder.IncrementVariable(var, rhsVariable);
            return var;
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

    return Tk::Sp<const Ir::CVariable>();
}

}
}
}