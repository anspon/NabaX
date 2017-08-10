#ifndef Naba_Lng_Ast_CIdentifier_H
#define Naba_Lng_Ast_CIdentifier_H

#include "Expression.h"

namespace Naba
{
namespace Lng
{

namespace Ast
{
class CIdentifier : public CExpression 
{
using BaseClass = CExpression;

public:
        CIdentifier(
            const StringToken* stringToken
            );

    Tk::Sp<const Ir::CVariable>
        MakeExpressionIr(
            Tk::Sp<Ir::CTypeManager> typeManager,
            Ir::CBlockBuilder& blockBuilder
            )const;
    
    const std::string 
        m_name;
};

}
}
}


#endif