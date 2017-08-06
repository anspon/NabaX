#include "TkPch.h"
#include "Exception.h"


namespace Tk
{
//--------------------------------------------------------------------------------------------------
CException::CException(
    const std::string& text
    ) : 
    m_text(text)
{
}
//--------------------------------------------------------------------------------------------------
const std::string& CException::Message(
    )const
{
    return m_text;
}
}