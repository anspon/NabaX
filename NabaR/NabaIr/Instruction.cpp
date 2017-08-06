#include "NabaIrPch.h"
#include "Instruction.h"

namespace NabaIr
{

//--------------------------------------------------------------------------------------------------
CInstruction::CInstruction(
    eInstructionType instructionType,
    Tk::Sp<const CVariable> lhsVariable,
    Tk::Sp<const CVariable> rhsVariable,
    Tk::Sp<const CLiteral> rhsLiteral,
    Tk::Sp<const CFunction> function,
    const Tk::SpList<const CVariable>& functionParameters,
    Tk::Sp<const CBlock> block
    ):
    m_instructionType(instructionType),
    m_lhsVariable(lhsVariable),
    m_rhsVariable(rhsVariable),
    m_rhsLiteral(rhsLiteral),
    m_function(function),
    m_functionParameters(functionParameters),
    m_block(block)
{
}
//--------------------------------------------------------------------------------------------------
CInstruction::~CInstruction()
{
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CVariable> CInstruction::LhsVariable() const
{
    return m_lhsVariable;
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CVariable> CInstruction::RhsVariable()const
{
    return m_rhsVariable;
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CLiteral> CInstruction::RhsLiteral() const
{
    return m_rhsLiteral;
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CFunction> CInstruction::Function() const
{
    return m_function;
}
//--------------------------------------------------------------------------------------------------
const Tk::SpList<const CVariable>& CInstruction::FunctionParameters() const
{
    return m_functionParameters;
}
//--------------------------------------------------------------------------------------------------
eInstructionType CInstruction::InstructionType(
    )const
{
    return m_instructionType;
}
Tk::Sp<const CBlock> CInstruction::Block() const
{
    return m_block;
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CInstruction> CInstruction::MakeCallFunction(
    Tk::Sp<const CFunction> function,
    const Tk::SpList<const CVariable>& parameters
    )
{
    return Tk::MakeSp<CInstruction>(itCallFunction, nullptr, nullptr, nullptr, function, parameters, nullptr );
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CInstruction> CInstruction::MakeIncrementLiteral(
    Tk::Sp<const CVariable> lhsVariable,
    Tk::Sp<const CLiteral> rhsLiteral
    )
{
    return Tk::MakeSp<CInstruction>(itIncrementLiteral, lhsVariable, nullptr, rhsLiteral, nullptr, Tk::SpList<const CVariable>(), nullptr );
}

//--------------------------------------------------------------------------------------------------
Tk::Sp<const CInstruction> CInstruction::MakeIncrementVariable(
    Tk::Sp<const CVariable> lhsVariable,
    Tk::Sp<const CVariable> rhsVariable
    )
{
    return Tk::MakeSp<CInstruction>(itIncrementVariable, lhsVariable, rhsVariable, nullptr, nullptr, Tk::SpList<const CVariable>(), nullptr );
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CInstruction> CInstruction::MakeAssignLiteral(
    Tk::Sp<const CVariable> lhsVariable,
    Tk::Sp<const CLiteral> rhsLiteral
    )
{
    return Tk::MakeSp<CInstruction>(itAssignLiteral, lhsVariable, nullptr, rhsLiteral, nullptr, Tk::SpList<const CVariable>(), nullptr );
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CInstruction> CInstruction::MakeAssignVariable(
    Tk::Sp<const CVariable> lhsVariable,
    Tk::Sp<const CVariable> rhsVariable
    )
{
    return Tk::MakeSp<CInstruction>(itAssignVariable, lhsVariable, rhsVariable, nullptr, nullptr, Tk::SpList<const CVariable>(), nullptr );
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CInstruction> CInstruction::MakeZeroVariable(
    Tk::Sp<const CVariable> lhsVariable
    )
{
    return Tk::MakeSp<CInstruction>(itZeroVariable, lhsVariable, nullptr, nullptr, nullptr, Tk::SpList<const CVariable>(), nullptr );
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CInstruction> CInstruction::MakeWhile(
    Tk::Sp<const CVariable> lhsVariable,
    Tk::Sp<const CBlock> block
    )
{
    return Tk::MakeSp<CInstruction>(itWhile, lhsVariable, nullptr, nullptr, nullptr, Tk::SpList<const CVariable>(), block );
}

}