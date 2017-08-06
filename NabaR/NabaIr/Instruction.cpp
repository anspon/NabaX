#include "NabaIrPch.h"
#include "Instruction.h"

namespace NabaIr
{

//--------------------------------------------------------------------------------------------------
CInstruction::CInstruction(
    eInstructionType instructionType,
    Tk::Sp<const CVariable> lhsVariable,
    Tk::Sp<const CVariable> rhsVariable,
    Tk::Sp<const CLiteral> rhsLiteral
    ):
    m_instructionType(instructionType),
    m_lhsVariable(lhsVariable),
    m_rhsVariable(rhsVariable),
    m_rhsLiteral(rhsLiteral)
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
eInstructionType CInstruction::InstructionType(
    )const
{
    return m_instructionType;
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CInstruction> CInstruction::MakeAssignLiteral(
    Tk::Sp<const CVariable> lhsVariable,
    Tk::Sp<const CLiteral> rhsLiteral
    )
{
    return Tk::MakeSp<CInstruction>(itAssignLiteral, lhsVariable, nullptr, rhsLiteral);
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CInstruction> CInstruction::MakeZeroVariable(
    Tk::Sp<const CVariable> lhsVariable
    )
{
    return Tk::MakeSp<CInstruction>(itZeroVariable, lhsVariable, nullptr, nullptr);
}

}