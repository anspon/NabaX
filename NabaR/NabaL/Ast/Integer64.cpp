#include "NabaLPch.h"

#include "Integer64.h"

#include "NabaIr/BlockBuilder.h"
#include "NabaIr/Literal.h"

namespace Naba
{
namespace Lng
{
namespace Ast
{
//--------------------------------------------------------------------------------------------------
CInteger64::CInteger64(
    const StringToken* stringToken
    ):
    BaseClass(stringToken)
{
    m_value = std::atoll(stringToken->m_string.c_str());
    delete stringToken;
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const Ir::CVariable> CInteger64::MakeExpressionIr(
    Tk::Sp<Ir::CTypeManager> typeManager,
    Ir::CBlockBuilder& blockBuilder
    )const
{
    auto var = blockBuilder.AddLocalVariable("i64", "");
    blockBuilder.AssignLiteral(var, Ir::CLiteral::MakeInt64(m_value) ) ;
    return var;
}

}
}
}
