#ifndef NabaL_CWhile_H
#define NabaL_CWhile_H

#include "BlockPart.h"

namespace Ast
{
class CExpression;
class CBlock;
class CIdentifier;

class CWhile : public CBlockPart
{
public:
    CWhile(
        const CIdentifier* blockName,
        const CExpression* expression,
        const CBlockPart* block
    );

    void
        MakeIr(
            Tk::Sp<NabaIr::CTypeManager> typeManager,
            NabaIr::CBlockBuilder& blockBuilder,
            Tk::SpList<const NabaIr::CFunction>& functions
            )const override;

    ~CWhile();

private:
    Tk::Sp<const CExpression>
        m_expression;
    
    Tk::Sp<const CBlockPart> 
        m_block;
};


}


#endif