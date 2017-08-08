#include "NabaLPch.h"
#include "Double.h"

#include "NabaIr/BlockBuilder.h"
#include "NabaIr/Literal.h"

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
Tk::Sp<const NabaIr::CVariable> CDouble::MakeExpressionIr(
    Tk::Sp<NabaIr::CTypeManager> typeManager,
    NabaIr::CBlockBuilder& blockBuilder
    )const
{
    auto var = blockBuilder.AddLocalVariable("double", "");
    blockBuilder.AssignLiteral(var, NabaIr::CLiteral::MakeDouble(m_value) ) ;
    return var;
}

}