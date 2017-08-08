#ifndef NabaL_Ast_CAssignment_H
#define NabaL_Ast_CAssignment_H

#include "Expression.h"

namespace Ast
{
class CIdentifier;

class CAssignment : public CBlockPart 
{
public:
    CAssignment(
        const CIdentifier* lhs, 
        const CExpression* rhs
        );
    
    void
        MakeFunctionIr(
            Tk::Sp<NabaIr::CTypeManager> typeManager,
            NabaIr::CBlockBuilder& blockBuilder
            )const override;

private:
    Tk::Sp<const CIdentifier> 
        m_lhs;

    Tk::Sp<const CExpression> 
        m_rhs;

};

}


#endif