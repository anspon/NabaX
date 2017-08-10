#ifndef Naba_Lng_Ast_CBinaryOperator_H
#define Naba_Lng_Ast_CBinaryOperator_H

#include "Expression.h"
namespace Naba
{
namespace Lng
{
namespace Ast
{
class CBinaryOperator : public CExpression 
{
public:
    CBinaryOperator(
        const CExpression* lhs, 
        int op, 
        const CExpression* rhs
        );

    Tk::Sp<const Ir::CVariable>
        MakeExpressionIr(
            Tk::Sp<Ir::CTypeManager> typeManager,
            Ir::CBlockBuilder& blockBuilder
            )const;

private:
    Tk::Sp<const CExpression> 
        m_lhs;
    
    int 
        m_op;

    Tk::Sp<const CExpression> 
        m_rhs;

};
}
}
}


#endif