#include "NabaLPch.h"
#include "MethodCall.h"
#include "Identifier.h"
#include "Expression.h"
#include "NabaIr/BlockBuilder.h"

#include "NabaIr/Variable.h"
#include "NabaIr/Function.h"

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
//--------------------------------------------------------------------------------------------------
Tk::Sp<const NabaIr::CVariable> CMethodCall::MakeExpressionIr(
    Tk::Sp<NabaIr::CTypeManager> typeManager,
    NabaIr::CBlockBuilder& blockBuilder
    ) const
{
    Tk::SpList<const NabaIr::CVariable> parameters;
    for( Tk::Sp<const CExpression> argumentExpression : m_arguments )
    {
        Tk::Sp<const NabaIr::CVariable> var = argumentExpression->MakeExpressionIr(typeManager, blockBuilder );
        parameters.push_back(var);
    }

    blockBuilder.CallFunction(m_id->m_name, parameters );
    return Tk::Sp<const NabaIr::CVariable>();
}

}