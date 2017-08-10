#include "NabaIrPch.h"
#include "FunctionBuilder.h"
#include "Function.h"
#include "Parameter.h"

namespace Naba
{
namespace Ir
{

CFunctionBuilder::CFunctionBuilder(
    Tk::Sp<CTypeManager> typeManager
    ):
    BaseClass(typeManager, nullptr)
{
}
//--------------------------------------------------------------------------------------------------
CFunctionBuilder::~CFunctionBuilder()
{
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<Ir::CFunction> CFunctionBuilder::Flush(
    const std::string& functionName
    )const
{
    return 
        Tk::MakeSp<Ir::CFunction>(
            functionName,
            m_parameters,
            BaseClass::Flush()
            );
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CVariable> CFunctionBuilder::AddParameter(
    const std::string& typeName,
    const std::string& variableName,
    eParameterType parameterType
    )
{
    auto variable = AddVariable(typeName, variableName);
    auto parameter = Tk::MakeSp<CParameter>(variable, parameterType );
    m_parameters.push_back(parameter);
    return variable;
}
//--------------------------------------------------------------------------------------------------

}
}
