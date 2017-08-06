#include "NabaIrPch.h"
#include "BlockBuilder.h"
#include "TypeManager.h"
#include "Instruction.h"
#include "Variable.h"
#include "StandardType.h"
#include "Block.h"

namespace NabaIr
{
//--------------------------------------------------------------------------------------------------
CBlockBuilder::CBlockBuilder(
    Tk::Sp<const CTypeManager> typeManager
    )
{
    m_typeManager = typeManager;
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CBlock> CBlockBuilder::Flush(
    ) const
{
    return Tk::MakeSp<CBlock>(m_variables, m_instructions);
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
    Tk::Sp<const CFunction> function,
    const Tk::SpList<const CVariable>& parameters
    )
{
    m_instructions.push_back(
        CInstruction::MakeCallFunction( function, parameters )
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
Tk::Sp<const CVariable> CBlockBuilder::MakeInt32(
    const std::string & name
    )
{
    return 
        Tk::MakeSp<CVariable>(
            m_typeManager->StandardType(stInt32),
            name
        );

}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CVariable> CBlockBuilder::AddInt32(
    const std::string & name
    )
{
    auto variable = MakeInt32(name);
    m_variables.push_back(variable);
    return variable;
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CVariable> CBlockBuilder::MakeInt64(
    const std::string & name
    )
{
    return 
        Tk::MakeSp<NabaIr::CVariable>(
            m_typeManager->StandardType(NabaIr::stInt64),
            name
        );
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CVariable> CBlockBuilder::AddInt64(
    const std::string & name
    )
{
    auto variable = MakeInt64(name);
    m_variables.push_back(variable);
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