#ifndef NabaL_Ast_CBlock_H
#define NabaL_Ast_CBlock_H

#include "Expression.h"

namespace NabaIr
{
class CBlockBuilder;
}

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
            Tk::Sp<NabaIr::CTypeManager> typeManager,
            NabaIr::CBlockBuilder& blockBuilder,
            Tk::SpList<const NabaIr::CFunction>& functions
            )const override;
    
private:        
    Tk::SpList<const CBlockPart>
        m_blockParts;
};

}


#endif