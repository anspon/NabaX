#include "NabaLPch.h"
#include "MethodCall.h"
#include "Identifier.h"

namespace Ast
{

//--------------------------------------------------------------------------------------------------
CMethodCall::CMethodCall(
    const CIdentifier* id, 
    const Tk::SpList<const CExpression>* arguments
    )
{
    m_id = Tk::AttachSp(id);
    if( arguments )
    {
        m_arguments = *arguments;
        delete arguments;
    }
}

}