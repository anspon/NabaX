#ifndef Naba_Lng_Ast_CInteger64_H
#define Naba_Lng_Ast_CInteger64_H

#include "Literal.h"

namespace Naba
{
namespace Lng
{

namespace Ast
{
class CInteger64 : public CLiteral 
{
using BaseClass = CLiteral;
public:
    CInteger64(
        const StringToken* stringToken
        );

    Tk::Sp<const Ir::CVariable>
        MakeExpressionIr(
            Tk::Sp<Ir::CTypeManager> typeManager,
            Ir::CBlockBuilder& blockBuilder
            )const;

    int64_t 
        m_value;

};
}
}
}


#endif