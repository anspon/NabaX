#ifndef Naba_Lng_Ast_CBlock_H
#define Naba_Lng_Ast_CBlock_H

#include "Expression.h"

namespace Naba
{
namespace Ir
{
class CBlockBuilder;
}
namespace Lng
{
namespace Ast
{
class CBlockPart;

class CBlock : public CBlockPart 
{
public:
    void
        AddBlockPart(
            const CBlockPart* part
            );
    
    void
        MakeIr(
            Tk::Sp<Ir::CTypeManager> typeManager,
            Ir::CBlockBuilder& blockBuilder,
            Tk::SpList<const Ir::CFunction>& functions
            )const override;
    
private:        
    Tk::SpList<const CBlockPart>
        m_blockParts;
};

}
}
}


#endif