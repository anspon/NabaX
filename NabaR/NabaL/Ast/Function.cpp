#include "NabaLPch.h"
#include "Function.h"

#include "Identifier.h"
#include "FunctionParameter.h"
#include "BlockPart.h"

namespace Ast
{
//--------------------------------------------------------------------------------------------------
CFunction::CFunction(
    const CIdentifier* type, 
    const CIdentifier* id, 
    const Tk::SpList<const CFunctionParameter>* arguments, 
    const CBlockPart* block
    )
{
    m_type = Tk::AttachSp(type);
    m_id = Tk::AttachSp(id);
    if( arguments )
    {
        m_arguments = *arguments;
        delete arguments;
    }
    m_block = Tk::AttachSp(block);
}
}