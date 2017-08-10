#include "NabaLPch.h"

#include "Identifier.h"

#include "NabaIr/BlockBuilder.h"

namespace Naba
{
namespace Lng
{
namespace Ast
{
CIdentifier::CIdentifier(
    const StringToken* stringToken
    ):
    m_name(stringToken->m_string) 
{
    m_position = stringToken->m_position;
    delete stringToken; 
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const Ir::CVariable> 
    CIdentifier::MakeExpressionIr(
        Tk::Sp<Ir::CTypeManager> typeManager,
        Ir::CBlockBuilder& blockBuilder
        ) const
{
    return blockBuilder.GetVariable(m_name);
}

}
}
}

