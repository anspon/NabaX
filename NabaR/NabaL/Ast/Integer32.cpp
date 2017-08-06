#include "NabaLPch.h"

#include "Integer32.h"

namespace Ast
{

//--------------------------------------------------------------------------------------------------
CInteger32::CInteger32( 
    const StringToken* stringToken
    ):
    BaseClass(stringToken->m_position)
{
    m_value = std::atoi(stringToken->m_string.c_str()); 
    delete stringToken;
}


}