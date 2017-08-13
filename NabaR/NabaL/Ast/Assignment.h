#ifndef Naba_Lng_Ast_CAssignment_H
#define Naba_Lng_Ast_CAssignment_H

#include "Expression.h"

namespace Naba
{
namespace Lng
{
namespace Ast
{
class CIdentifier;

class CAssignment : public CBlockPart 
{
    using BaseClass = CBlockPart;
public:
    CAssignment(
        const CIdentifier* lhs, 
        const CExpression* rhs
        );
    
    void
        MakeIr(
            Tk::Sp<Ir::CTypeManager> typeManager,
            Ir::CBlockBuilder& blockBuilder,
            Tk::SpList<const Ir::CFunction>& functions
            )const override;

private:
    Tk::Sp<const CIdentifier> 
        m_lhs;

    Tk::Sp<const CExpression> 
        m_rhs;

};

}
}
}


#endif