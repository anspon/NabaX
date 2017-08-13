#include "NabaLPch.h"

#include "Struct.h"
#include "Identifier.h"

namespace Naba
{
namespace Lng
{
namespace Ast
{
//--------------------------------------------------------------------------------------------------
CStruct::CStruct(
    const CIdentifier* name,
    const Tk::SpList<const CStructPart>* list 
    ):
    BaseClass(bptStruct)
{
    m_name = Tk::AttachSp(name);
    if( list )
    {
        m_parts = *list;
        delete list;
    }

}

}
}
}