#include "NabaIrPch.h"
#include "BlockBuilder.h"
#include "TypeManager.h"
#include "Instruction.h"
#include "Variable.h"
#include "StandardType.h"
#include "Block.h"

#include "Tk/Exception.h"

namespace Naba
{
namespace Ir
{
//--------------------------------------------------------------------------------------------------
CBlockBuilder::CBlockBuilder(
    Tk::Sp<CTypeManager> typeManager,
    const CBlockBuilder* parentBlock
    ):
    m_parentBlock(parentBlock)
{
    m_typeManager = typeManager;

}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CBlock> CBlockBuilder::Flush(
    ) const
{
    return Tk::MakeSp<CBlock>(m_localVariables, m_instructions);
}
//--------------------------------------------------------------------------------------------------
void CBlockBuilder::AssignVariable(
    Tk::Sp<const CVariable> lhs,
    Tk::Sp<const CVariable> rhs
    )
{
    m_instructions.push_back(
        CInstruction::MakeAssignVariable( lhs, rhs )
        );
}
//--------------------------------------------------------------------------------------------------
void CBlockBuilder::AssignLiteral(
    Tk::Sp<const CVariable> lhs,
    Tk::Sp<const CLiteral> rhs
    )
{
    m_instructions.push_back(
        CInstruction::MakeAssignLiteral( lhs, rhs )
        );
}
//--------------------------------------------------------------------------------------------------
void CBlockBuilder::IncrementVariable(
    Tk::Sp<const CVariable> lhs,
    Tk::Sp<const CVariable> rhs
    )
{
    m_instructions.push_back(
        CInstruction::MakeIncrementVariable( lhs, rhs )
        );
}
//--------------------------------------------------------------------------------------------------
void CBlockBuilder::IncrementLiteral(
    Tk::Sp<const CVariable> lhs,
    Tk::Sp<const CLiteral> rhs
    )
{
    m_instructions.push_back(
        CInstruction::MakeIncrementLiteral( lhs, rhs )
        );
}
//--------------------------------------------------------------------------------------------------
void CBlockBuilder::CallFunction(
    const std::string& functionName,
    const Tk::SpList<const CVariable>& parameters
    )
{
    m_instructions.push_back(
        CInstruction::MakeCallFunction( functionName, parameters )
        );
}
//--------------------------------------------------------------------------------------------------
void CBlockBuilder::While(
    Tk::Sp<const CVariable> variable,
    Tk::Sp<const CBlock> block
    )
{
    m_instructions.push_back(
        CInstruction::MakeWhile( variable, block )
        );
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CVariable> CBlockBuilder::AddLocalVariable(
    const std::string& typeName, 
    const std::string& variableName
    )
{
    auto variable = AddVariable(typeName, variableName);
    m_localVariables.push_back(variable);
    return variable;
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CVariable> CBlockBuilder::GetVariable(
    const std::string& variableName
    )const
{
    Tk::Sp<const CVariable> result;

    auto it = m_variables.find(variableName);
    if( it != m_variables.end() )
    {
        result = it->second;
    }
    else
    {
        if( m_parentBlock )
        {
            result = m_parentBlock->GetVariable(variableName);
        }
    }
    TK_ASSERT( nullptr != result, "No such variable" );
    return result;
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CVariable> CBlockBuilder::AddVariable(
    const std::string& typeName,
    const std::string& variableName
    )
{
    std::string actualName = variableName;
    if( !actualName.size() )
    {
        static int count = 0;
        count++;

        actualName = "anonymous" + std::to_string(count);
    }
    auto variable = 
        Tk::MakeSp<Ir::CVariable>(
            m_typeManager->Type(typeName),
            actualName
        );
    m_variables[variableName] = variable;
    return variable;
}
//--------------------------------------------------------------------------------------------------
void CBlockBuilder::AddBinaryOperationBoolResult(
    eBinaryBoolInstruction binaryBoolInstruction,
    Tk::Sp<const CVariable> result,
    Tk::Sp<const CVariable> lhs,
    Tk::Sp<const CVariable> rhs
    )
{
    m_instructions.push_back(
        CInstruction::MakeBinaryBoolInstruction( binaryBoolInstruction, result, lhs, rhs )
        );
}
//--------------------------------------------------------------------------------------------------
void CBlockBuilder::ZeroVariable(
    Tk::Sp<const CVariable> variable
    )
{
    m_instructions.push_back(
        CInstruction::MakeZeroVariable( variable )
        );
    
}

}
}