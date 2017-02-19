#include "NabaLPch.h"

#include "Integer64.h"


namespace Ast
{
//--------------------------------------------------------------------------------------------------
CInteger64::CInteger64(
    const std::string* value
    )
{
    m_value = std::atoll((*value).c_str());
    m_originalText = *value;
    delete value;
}

}