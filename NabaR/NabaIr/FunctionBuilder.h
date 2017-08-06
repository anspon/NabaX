#ifndef NabaIr_CFunctionBuilder_H
#define NabaIr_CFunctionBuilder_H

#include "BlockBuilder.h"
#include "eParameterType.h"

namespace NabaIr
{
class CFunction;
class CParameter;

class CFunctionBuilder : public CBlockBuilder
{
    using BaseClass = CBlockBuilder;
public:
    CFunctionBuilder(
        Tk::Sp<const CTypeManager> typeManager
        );
    ~CFunctionBuilder();

    Tk::Sp<NabaIr::CFunction>
        Flush(
            const std::string& functionName
            )const;

    Tk::Sp<const CVariable>
        AddParameterInt32(
            const std::string& name,
            eParameterType parameterType
            );

private:
    Tk::SpList<const CParameter>
        m_parameters;

};


}

#endif