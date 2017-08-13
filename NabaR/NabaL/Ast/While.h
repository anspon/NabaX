#ifndef Naba_Lng_Ast_CWhile_H
#define Naba_Lng_Ast_CWhile_H

#include "BlockPart.h"

namespace Naba
{
namespace Lng
{
namespace Ast
{
class CExpression;
class CBlock;
class CIdentifier;

class CWhile : public CBlockPart
{
    using BaseClass = CBlockPart;
public:
    CWhile(
        const CIdentifier* blockName,
        const CExpression* expression,
        const CBlockPart* block
    );

    void
        MakeIr(
            Tk::Sp<Ir::CTypeManager> typeManager,
            Ir::CBlockBuilder& blockBuilder,
            Tk::SpList<const Ir::CFunction>& functions
            )const override;

    ~CWhile();

private:
    Tk::Sp<const CExpression>
        m_expression;
    
    Tk::Sp<const CBlockPart> 
        m_block;
};


}
}
}


#endif