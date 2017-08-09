#ifndef NabaL_CFor_H
#define NabaL_CFor_H

#include "BlockPart.h"

namespace Ast
{
class CExpression;
class CBlock;
class CIdentifier;

class CFor : public CBlockPart
{
public:
    CFor(
        const CIdentifier* blockName,
        const CIdentifier* loopVariable,
        const CExpression* expression,
        const CBlockPart* block
    );

    void
        MakeIr(
            Tk::Sp<NabaIr::CTypeManager> typeManager,
            NabaIr::CBlockBuilder& blockBuilder,
            Tk::SpList<const NabaIr::CFunction>& functions
            )const override;

    ~CFor();

private:
    Tk::Sp<const CExpression>
        m_expression;
    
    Tk::Sp<const CBlockPart> 
        m_block;
};


}


#endif