#include "NabaLPch.h"
#include "FunctionParameter.h"

#include "Identifier.h"
#include "Expression.h"

namespace Naba
{
namespace Lng
{
namespace Ast
{
//--------------------------------------------------------------------------------------------------
CFunctionParameter::CFunctionParameter(
    const CIdentifier* type, 
    const CIdentifier* id
    )
{
    m_type = Tk::AttachSp(type);
    m_id = Tk::AttachSp(id);
}

}
}
}
