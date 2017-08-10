#ifndef Naba_Lng_Ast_CMethodCall_H
#define Naba_Lng_Ast_CMethodCall_H

#include "Expression.h"

namespace Naba
{
namespace Lng
{
namespace Ast
{
class CIdentifier;
class CExpression;

class CMethodCall : public CExpression 
{
public:
    CMethodCall(
        const CIdentifier* id, 
        const Tk::SpList<const CExpression>* arguments
        ) ;

    Tk::Sp<const Ir::CVariable>
        MakeExpressionIr(
            Tk::Sp<Ir::CTypeManager> typeManager,
            Ir::CBlockBuilder& blockBuilder
            )const override;
    
private:
    Tk::Sp<const CIdentifier>
        m_id;

    Tk::SpList<const CExpression>
        m_arguments;

};
}
}
}


#endif