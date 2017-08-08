#include "NabaLPch.h"

#include "Integer64.h"

#include "NabaIr/BlockBuilder.h"
#include "NabaIr/Literal.h"

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
Tk::Sp<const NabaIr::CVariable> CInteger64::MakeExpressionIr(
    Tk::Sp<NabaIr::CTypeManager> typeManager,
    NabaIr::CBlockBuilder& blockBuilder
    )const
{
    auto var = blockBuilder.AddLocalVariable("i64", "");
    blockBuilder.AssignLiteral(var, NabaIr::CLiteral::MakeInt64(m_value) ) ;
    return var;
}

}