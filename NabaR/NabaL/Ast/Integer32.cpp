#include "NabaLPch.h"

#include "Integer32.h"

#include "NabaIr/BlockBuilder.h"
#include "NabaIr/Literal.h"


namespace Ast
{

//--------------------------------------------------------------------------------------------------
CInteger32::CInteger32( 
    const StringToken* stringToken
    ):
    BaseClass(stringToken)
{
    m_value = std::atoi(stringToken->m_string.c_str()); 
    delete stringToken;
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const NabaIr::CVariable> CInteger32::MakeExpressionIr(
    Tk::Sp<NabaIr::CTypeManager> typeManager,
    NabaIr::CBlockBuilder& blockBuilder
    )const
{
    auto var = blockBuilder.AddLocalVariable("i32", "");
    blockBuilder.AssignLiteral(var, NabaIr::CLiteral::MakeInt32(m_value) ) ;
    return var;
}


}