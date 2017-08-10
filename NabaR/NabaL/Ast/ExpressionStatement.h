#ifndef Naba_Lng_Ast_CExpressionStatement_H
#define Naba_Lng_Ast_CExpressionStatement_H

#include "Statement.h"

namespace Naba
{
namespace Lng
{

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
            Tk::Sp<Ir::CTypeManager> typeManager,
            Ir::CBlockBuilder& blockBuilder,
            Tk::SpList<const Ir::CFunction>& functions
            ) const override;

    Tk::Sp<const CExpression> 
        m_expression;
};

}
}
}


#endif