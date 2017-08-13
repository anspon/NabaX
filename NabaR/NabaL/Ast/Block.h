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
class CStruct;
class CFunction;

enum eBlockType
{
    btUnknown,
    btFileScope,
    btFunctionScope,
    btAnonymous,
    btIf,
    btWhile
};

class CBlock : public CBlockPart 
{
    using BaseClass = CBlockPart;
    DECLARE_SHARED_FROM_THIS(CBlock)
public:
        CBlock(
            );

    void
        AddBlockPart(
            CBlockPart* part
            );
    
    void
        SetBlockType(
            eBlockType blockType
            );
    

    using ForEachBlockFunctionT = std::function< void(Tk::Sp<const CBlock> astBlock )>;
    void 
        ForEachBlock(
            ForEachBlockFunctionT forEachBlockFunction
            )const;
    
    void
        MakeIr(
            Tk::Sp<Ir::CTypeManager> typeManager,
            Ir::CBlockBuilder& blockBuilder,
            Tk::SpList<const Ir::CFunction>& functions
            )const override;
    
    void
        Initialize(
            );

protected:
    void
        AddChildBlock(
            Tk::Sp<CBlock> block
            );
private:     
    eBlockType 
        m_blockType;

    Tk::SpList<const CBlockPart>
        m_blockParts;

    Tk::SpList<CBlock>
        m_ChildBlocks;

    Tk::SpList<const CStruct>
        m_structs;
    
    Tk::WeakSp<const CBlock>
        m_parentBlock;
};

}
}
}


#endif