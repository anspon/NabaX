#ifndef NabaIr_CInstruction_H
#define NabaIr_CInstruction_H

#include "eInstructionType.h"

namespace NabaIr
{

class CVariable;
class CLiteral;

class CInstruction
{
public:
    
    static Tk::Sp<const CInstruction>
        MakeAssignLiteral(
            Tk::Sp<const CVariable> lhsVariable,
            Tk::Sp<const CLiteral> rhsLiteral
            );

    static Tk::Sp<const CInstruction>
        MakeZeroVariable(
            Tk::Sp<const CVariable> lhsVariable
            );

    CInstruction(
        eInstructionType instructionType,
        Tk::Sp<const CVariable> lhsVariable,
        Tk::Sp<const CVariable> rhsVariable,
        Tk::Sp<const CLiteral> rhsLiteral
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

    eInstructionType 
        InstructionType(
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

};


}


#endif