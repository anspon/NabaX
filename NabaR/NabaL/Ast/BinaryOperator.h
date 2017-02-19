#ifndef NabaL_Ast_CBinaryOperator_H
#define NabaL_Ast_CBinaryOperator_H

#include "Expression.h"

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

private:
    Tk::Sp<const CExpression> 
        m_lhs;
    
    int 
        m_op;

    Tk::Sp<const CExpression> 
        m_rhs;

};}


#endif