#include "NabaLPch.h"
#include "Double.h"

#include "NabaIr/BlockBuilder.h"
#include "NabaIr/Literal.h"

namespace Naba
{
namespace Lng
{
namespace Ast
{

//--------------------------------------------------------------------------------------------------
CDouble::CDouble(
    const StringToken* stringToken
    ):
    BaseClass(stringToken)
{
    m_value = atof(stringToken->m_string.c_str());
    delete stringToken;
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const Ir::CVariable> CDouble::MakeExpressionIr(
    Tk::Sp<Ir::CTypeManager> typeManager,
    Ir::CBlockBuilder& blockBuilder
    )const
{
    auto var = blockBuilder.AddLocalVariable("double", "");
    blockBuilder.AssignLiteral(var, Ir::CLiteral::MakeDouble(m_value) ) ;
    return var;
}

}
}
}
