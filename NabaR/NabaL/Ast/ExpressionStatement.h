#ifndef NabaL_Ast_CExpressionStatement_H
#define NabaL_Ast_CExpressionStatement_H

#include "Statement.h"

namespace Ast
{
class CExpression;

class CExpressionStatement : public CStatement 
{
public:
        CExpressionStatement(
            const CExpression* expression
            );

    void 
        MakeIr(
            Tk::Sp<NabaIr::CTypeManager> typeManager,
            NabaIr::CBlockBuilder& blockBuilder,
            Tk::SpList<const NabaIr::CFunction>& functions
            ) const override;

    Tk::Sp<const CExpression> 
        m_expression;
};

}


#endif