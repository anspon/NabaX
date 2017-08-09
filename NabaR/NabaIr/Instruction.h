#ifndef NabaIr_CInstruction_H
#define NabaIr_CInstruction_H

#include "eInstructionType.h"
#include "eBinaryBoolInstruction.h"

namespace NabaIr
{

class CVariable;
class CLiteral;
class CFunction;
class CVariable;
class CBlock;

class CInstruction
{
public:
    
    static Tk::Sp<const CInstruction>
        MakeIncrementLiteral(
            Tk::Sp<const CVariable> lhsVariable,
            Tk::Sp<const CLiteral> rhsLiteral
            );
    static Tk::Sp<const CInstruction>
        MakeIncrementVariable(
            Tk::Sp<const CVariable> lhsVariable,
            Tk::Sp<const CVariable> rhsVariable
            );

    static Tk::Sp<const CInstruction>
        MakeAssignLiteral(
            Tk::Sp<const CVariable> lhsVariable,
            Tk::Sp<const CLiteral> rhsLiteral
            );
    static Tk::Sp<const CInstruction>
        MakeAssignVariable(
            Tk::Sp<const CVariable> lhsVariable,
            Tk::Sp<const CVariable> rhsVariable
            );
    static Tk::Sp<const CInstruction>
        MakeCallFunction(
            const std::string& functionName,
            const Tk::SpList<const CVariable>& parameters
            );
    
    static Tk::Sp<const CInstruction>
        MakeBinaryBoolInstruction(
            eBinaryBoolInstruction type,
            Tk::Sp<const CVariable> result,
            Tk::Sp<const CVariable> lhsVariable,
            Tk::Sp<const CVariable> rhsVariable
            );


    static Tk::Sp<const CInstruction>
        MakeZeroVariable(
            Tk::Sp<const CVariable> lhsVariable
            );

    static Tk::Sp<const CInstruction>
        MakeWhile(
            Tk::Sp<const CVariable> variable,
            Tk::Sp<const CBlock> block
            );

    CInstruction(
        eInstructionType instructionType
        );
    ~CInstruction();

    Tk::Sp<const CVariable>
        ResultVariable(
            )const;

    Tk::CNullableT<eBinaryBoolInstruction>
        BinaryBoolInstruction(
            )const;   

    Tk::Sp<const CVariable> 
        LhsVariable(
            )const;

    Tk::Sp<const CVariable> 
        RhsVariable(
            )const;
        
    Tk::Sp<const CLiteral> 
        RhsLiteral(
            )const;
    
    const Tk::CNullableT<std::string>& 
        FunctionName(
            )const;
    
    const Tk::SpList<const CVariable>& 
        FunctionParameters(
            )const;

    eInstructionType 
        InstructionType(
            )const;
    Tk::Sp<const CBlock> 
        Block(
            )const;
private:
    
    Tk::CNullableT<eBinaryBoolInstruction>
        m_binaryBoolInstruction;

    Tk::Sp<const CVariable>
        m_resultVariable;

    eInstructionType 
        m_instructionType;

    Tk::Sp<const CVariable> 
        m_lhsVariable;
    
    Tk::Sp<const CVariable> 
        m_rhsVariable;

    Tk::Sp<const CLiteral> 
        m_rhsLiteral;

    Tk::CNullableT<std::string>
        m_functionName;
    
    Tk::SpList<const CVariable> 
        m_functionParameters;
    
    Tk::Sp<const CBlock> 
        m_block;

};


}


#endif