#ifndef NabaIr_eInstructionType_H
#define NabaIr_eInstructionType_H


namespace Naba
{
namespace Ir
{

enum eInstructionType
{
    itAssignLiteral,
    itAssignVariable,
    itZeroVariable,
    itIncrementLiteral,
    itDecrementLiteral,
    itIncrementVariable,
    itDecrementVariable,
    itCallFunction,
    itWhile,
    itBinaryBoolOperation
};


}
}

#endif