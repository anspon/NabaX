#ifndef NabaL_Ast_CExpression_H
#define NabaL_Ast_CExpression_H

#include "BlockPart.h"

namespace NabaIr
{
class CVariable;
class CTypeManager;
class CBlockBuilder;
class CType;
}

namespace Ast
{
class CExpression : public CBlockPart
{
public:
        CExpression(
            );
    
    Tk::Sp<const NabaIr::CType>
        Type(
            Tk::Sp<NabaIr::CTypeManager> typeManager
            )const;

    void MakeIr(
        Tk::Sp<NabaIr::CTypeManager> typeManager,
        NabaIr::CBlockBuilder& blockBuilder,
        Tk::SpList<const NabaIr::CFunction>& functions
        ) const override;

    virtual Tk::Sp<const NabaIr::CVariable>
        MakeExpressionIr(
            Tk::Sp<NabaIr::CTypeManager> typeManager,
            NabaIr::CBlockBuilder& blockBuilder
            )const = 0;
};

}


#endif