#include "NabaLPch.h"

#include "Integer32.h"

namespace Ast
{

//--------------------------------------------------------------------------------------------------
CInteger32::CInteger32( 
    const std::string* value
    )
{
    m_value = std::atoi((*value).c_str()); 
    delete value;
}


}