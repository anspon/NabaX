#include "NabaLPch.h"

#include "Literal.h"

namespace Ast
{
CLiteral::CLiteral(
    const StringToken* stringToken
    )
{
    m_position = stringToken->m_position;
    m_originalText = stringToken->m_string;
}
}

