#ifndef Naba_Lng_Ast_CFor_H
#define Naba_Lng_Ast_CFor_H

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
            Tk::Sp<Ir::CTypeManager> typeManager,
            Ir::CBlockBuilder& blockBuilder,
            Tk::SpList<const Ir::CFunction>& functions
            )const override;

    ~CFor();

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