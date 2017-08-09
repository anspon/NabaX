#include "NabaLPch.h"

#include "Identifier.h"

#include "NabaIr/BlockBuilder.h"

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
Tk::Sp<const NabaIr::CVariable> 
    CIdentifier::MakeExpressionIr(
        Tk::Sp<NabaIr::CTypeManager> typeManager,
        NabaIr::CBlockBuilder& blockBuilder
        ) const
{
    return blockBuilder.GetVariable(m_name);
}
//--------------------------------------------------------------------------------------------------
CIdentifierChain::CIdentifierChain()
{
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const NabaIr::CVariable> CIdentifierChain::MakeExpressionIr(
    Tk::Sp<NabaIr::CTypeManager> typeManager,
    NabaIr::CBlockBuilder& blockBuilder
    ) const
{
    return Tk::Sp<const NabaIr::CVariable>();
}
//--------------------------------------------------------------------------------------------------
void CIdentifierChain::AddIdentifier(
    const CIdentifier* identifier
    )
{
}

}

