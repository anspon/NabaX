#include "NabaLPch.h"

#include "Identifier.h"

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

}

