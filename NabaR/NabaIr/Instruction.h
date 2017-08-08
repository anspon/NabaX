#ifndef NabaIr_CInstruction_H
#define NabaIr_CInstruction_H

#include "eInstructionType.h"

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
        MakeZeroVariable(
            Tk::Sp<const CVariable> lhsVariable
            );

    static Tk::Sp<const CInstruction>
        MakeWhile(
            Tk::Sp<const CVariable> variable,
            Tk::Sp<const CBlock> block
            );

    CInstruction(
        eInstructionType instructionType,
        Tk::Sp<const CVariable> lhsVariable,
        Tk::Sp<const CVariable> rhsVariable,
        Tk::Sp<const CLiteral> rhsLiteral,
        const std::string& functionName,
        const Tk::SpList<const CVariable>& functionParameters,
        Tk::Sp<const CBlock> block
        );
    ~CInstruction();

    Tk::Sp<const CVariable> 
        LhsVariable(
            )const;

    Tk::Sp<const CVariable> 
        RhsVariable(
            )const;
        
    Tk::Sp<const CLiteral> 
        RhsLiteral(
            )const;
    
    const std::string& 
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
    eInstructionType 
        m_instructionType;

    const Tk::Sp<const CVariable> 
        m_lhsVariable;
    
    const Tk::Sp<const CVariable> 
        m_rhsVariable;

    const Tk::Sp<const CLiteral> 
        m_rhsLiteral;

    const std::string& 
        m_functionName;
    
    const Tk::SpList<const CVariable> 
        m_functionParameters;
    
    const Tk::Sp<const CBlock> 
        m_block;

};


}


#endif