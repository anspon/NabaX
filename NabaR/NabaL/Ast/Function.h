#ifndef Naba_Lng_Ast_CFunction_H
#define Naba_Lng_Ast_CFunction_H


#include "Statement.h"

namespace Naba
{
namespace Lng
{

namespace Ast
{
class CIdentifier;
class CFunctionParameter;

class CFunction : public CStatement 
{
public:
    CFunction(
        const CIdentifier* type, 
        const CIdentifier* id, 
        const Tk::SpList<const CFunctionParameter>* arguments, 
        const CBlockPart* block
        );

    void
        MakeIr(
            Tk::Sp<Ir::CTypeManager> typeManager,
            Ir::CBlockBuilder& blockBuilder,
            Tk::SpList<const Ir::CFunction>& functions
            )const override;
private:
    Tk::Sp<const CIdentifier> 
        m_type;

    Tk::Sp<const CIdentifier> 
        m_id;
    
    Tk::SpList<const CFunctionParameter>
        m_arguments;
    
    Tk::Sp<const CBlockPart> 
        m_block;

};

}
}
}


#endif