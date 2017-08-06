#ifndef NabaIr_eInstructionType_H
#define NabaIr_eInstructionType_H


namespace NabaIr
{

enum eInstructionType
{
    itAssignLiteral,
    itAssignVariable,
    itZeroVariable,
    itIncrementLiteral,
    itDecrementLiteral,
    itIncrementVariable,
    itDecrementVariable
};


}

#endif