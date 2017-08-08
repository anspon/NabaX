#include "NabaIrPch.h"
#include "BlockBuilder.h"
#include "TypeManager.h"
#include "Instruction.h"
#include "Variable.h"
#include "StandardType.h"
#include "Block.h"

#include "Tk/Exception.h"

namespace NabaIr
{
//--------------------------------------------------------------------------------------------------
CBlockBuilder::CBlockBuilder(
    Tk::Sp<CTypeManager> typeManager
    )
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
    )
{
    auto it = m_variables.find(variableName);
    TK_ASSERT( it != m_variables.end(), "No such variable" );
    return it->second;
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
        Tk::MakeSp<NabaIr::CVariable>(
            m_typeManager->Type(typeName),
            actualName
        );
    m_variables[variableName] = variable;
    return variable;
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