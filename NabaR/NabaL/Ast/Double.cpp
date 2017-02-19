#include "NabaLPch.h"
#include "Double.h"


namespace Ast
{

//--------------------------------------------------------------------------------------------------
CDouble::CDouble(
    const std::string* value
    )
{
    m_value = atof((*value).c_str());
    m_originalText = *value;
    delete value;
}

}