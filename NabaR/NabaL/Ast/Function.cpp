#include "NabaLPch.h"
#include "Function.h"

#include "Identifier.h"
#include "FunctionParameter.h"
#include "BlockPart.h"

#include "NabaIr/FunctionBuilder.h"
#include "NabaIr/Literal.h"

namespace Naba
{
namespace Lng
{
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
//--------------------------------------------------------------------------------------------------
void CFunction::MakeIr(
    Tk::Sp<Ir::CTypeManager> typeManager,
    Ir::CBlockBuilder& blockBuilder,
    Tk::SpList<const Ir::CFunction>& functions
    ) const
{
    Ir::CFunctionBuilder functionBuilder(typeManager);
    
    for( Tk::Sp<const CFunctionParameter> functionParameter : m_arguments )
    {
        functionBuilder.AddParameter(functionParameter->m_type->m_name, functionParameter->m_id->m_name, Ir::ptIn );
    }

    m_block->MakeIr(typeManager, functionBuilder, functions);
    functions.push_back(functionBuilder.Flush(m_id->m_name));
}

}
}
}
