#include "NabaLPch.h"

#include "Integer64.h"


namespace Ast
{
//--------------------------------------------------------------------------------------------------
CInteger64::CInteger64(
    const StringToken* stringToken
    ):
    BaseClass(stringToken->m_position)
{
    m_value = std::atoll(stringToken->m_string.c_str());
    m_originalText = stringToken->m_string;
    delete stringToken;
}

}