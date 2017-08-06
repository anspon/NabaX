#include "NabaIrPch.h"
#include "FunctionBuilder.h"
#include "Function.h"
#include "Parameter.h"

namespace NabaIr
{

CFunctionBuilder::CFunctionBuilder(
    Tk::Sp<const CTypeManager> typeManager
    ):
    BaseClass(typeManager)
{
}
//--------------------------------------------------------------------------------------------------
CFunctionBuilder::~CFunctionBuilder()
{
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<NabaIr::CFunction> CFunctionBuilder::Flush(
    const std::string& functionName
    )const
{
    return 
        Tk::MakeSp<NabaIr::CFunction>(
            functionName,
            m_parameters,
            BaseClass::Flush()
            );
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CVariable> CFunctionBuilder::AddParameterInt32(
    const std::string & name,
    eParameterType parameterType
    )
{
    auto variable = MakeInt32(name);
    auto parameter = Tk::MakeSp<CParameter>(variable, parameterType );
    m_parameters.push_back(parameter);
    return variable;
}
//--------------------------------------------------------------------------------------------------

}