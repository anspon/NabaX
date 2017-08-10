#include "NabaIrPch.h"
#include "Instruction.h"

namespace Naba
{
namespace Ir
{

//--------------------------------------------------------------------------------------------------
CInstruction::CInstruction(
    eInstructionType instructionType
    ):
    m_instructionType(instructionType)
{
}
//--------------------------------------------------------------------------------------------------
CInstruction::~CInstruction()
{
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CVariable> CInstruction::ResultVariable() const
{
    return m_resultVariable;
}
//--------------------------------------------------------------------------------------------------
Tk::CNullableT<eBinaryBoolInstruction> CInstruction::BinaryBoolInstruction() const
{
    return m_binaryBoolInstruction;
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
const Tk::CNullableT<std::string>&  CInstruction::FunctionName() const
{
    return m_functionName;
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
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CBlock> CInstruction::Block() const
{
    return m_block;
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CInstruction> CInstruction::MakeCallFunction(
    const std::string& functionName,
    const Tk::SpList<const CVariable>& parameters
    )
{
    Tk::Sp<CInstruction> instruction = Tk::MakeSp<CInstruction>(itCallFunction);
    instruction->m_functionName = functionName;
    instruction->m_functionParameters = parameters;
    return instruction;
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CInstruction> CInstruction::MakeBinaryBoolInstruction(
    eBinaryBoolInstruction type,
    Tk::Sp<const CVariable> result,
    Tk::Sp<const CVariable> lhsVariable,
    Tk::Sp<const CVariable> rhsVariable
    )
{
    Tk::Sp<CInstruction> instruction = Tk::MakeSp<CInstruction>(itBinaryBoolOperation);
    instruction->m_binaryBoolInstruction = type;
    instruction->m_resultVariable = result;
    instruction->m_lhsVariable = lhsVariable;
    instruction->m_rhsVariable = rhsVariable;
    return instruction;
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CInstruction> CInstruction::MakeIncrementLiteral(
    Tk::Sp<const CVariable> lhsVariable,
    Tk::Sp<const CLiteral> rhsLiteral
    )
{
    Tk::Sp<CInstruction> instruction = Tk::MakeSp<CInstruction>(itIncrementLiteral);
    instruction->m_lhsVariable = lhsVariable;
    instruction->m_rhsLiteral = rhsLiteral;
    return instruction;
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CInstruction> CInstruction::MakeIncrementVariable(
    Tk::Sp<const CVariable> lhsVariable,
    Tk::Sp<const CVariable> rhsVariable
    )
{
    Tk::Sp<CInstruction> instruction = Tk::MakeSp<CInstruction>(itIncrementVariable);
    instruction->m_lhsVariable = lhsVariable;
    instruction->m_rhsVariable = rhsVariable;
    return instruction;
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CInstruction> CInstruction::MakeAssignLiteral(
    Tk::Sp<const CVariable> lhsVariable,
    Tk::Sp<const CLiteral> rhsLiteral
    )
{
    Tk::Sp<CInstruction> instruction = Tk::MakeSp<CInstruction>(itAssignLiteral);
    instruction->m_lhsVariable = lhsVariable;
    instruction->m_rhsLiteral = rhsLiteral;
    return instruction;
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CInstruction> CInstruction::MakeAssignVariable(
    Tk::Sp<const CVariable> lhsVariable,
    Tk::Sp<const CVariable> rhsVariable
    )
{
    Tk::Sp<CInstruction> instruction = Tk::MakeSp<CInstruction>(itAssignVariable);
    instruction->m_lhsVariable = lhsVariable;
    instruction->m_rhsVariable = rhsVariable;
    return instruction;
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CInstruction> CInstruction::MakeZeroVariable(
    Tk::Sp<const CVariable> lhsVariable
    )
{
    Tk::Sp<CInstruction> instruction = Tk::MakeSp<CInstruction>(itZeroVariable);
    instruction->m_lhsVariable = lhsVariable;
    return instruction;
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CInstruction> CInstruction::MakeWhile(
    Tk::Sp<const CVariable> lhsVariable,
    Tk::Sp<const CBlock> block
    )
{
    Tk::Sp<CInstruction> instruction = Tk::MakeSp<CInstruction>(itWhile);
    instruction->m_lhsVariable = lhsVariable;
    instruction->m_block = block;
    return instruction;
}

}
}
