#include "NabaLPch.h"
#include "Double.h"


namespace Ast
{

//--------------------------------------------------------------------------------------------------
CDouble::CDouble(
    const StringToken* stringToken
    ):
    BaseClass(stringToken->m_position)
{
    m_value = atof(stringToken->m_string.c_str());
    m_originalText = stringToken->m_string;
    delete stringToken;
}

}