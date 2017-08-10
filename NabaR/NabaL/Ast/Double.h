#ifndef Naba_Lng_Ast_CDouble_H
#define Naba_Lng_Ast_CDouble_H

#include "Literal.h"

namespace Naba
{
namespace Lng
{

namespace Ast
{
class CDouble : public CLiteral
{
using BaseClass = CLiteral;
public:
    CDouble(
        const StringToken* stringToken
        );

    Tk::Sp<const Ir::CVariable>
        MakeExpressionIr(
            Tk::Sp<Ir::CTypeManager> typeManager,
            Ir::CBlockBuilder& blockBuilder
            )const;
    
       
private:    
    double 
        m_value;

};

}
}
}


#endif