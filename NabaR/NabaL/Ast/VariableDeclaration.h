#ifndef Naba_Lng_Ast_CVariableDeclaration_H
#define Naba_Lng_Ast_CVariableDeclaration_H

#include "Statement.h"

namespace Naba
{
namespace Lng
{
namespace Ast
{
class CIdentifier;
class CExpression;

class CVariableDeclaration : public CStatement 
{
public:

    CVariableDeclaration(
        const CIdentifier* type, 
        const CIdentifier* id, 
        const CExpression* assignmentExpr
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
    
    Tk::Sp<const CExpression> 
        m_assignmentExpr;
};
}
}
}


#endif