#ifndef NabaL_Ast_CVariableDeclaration_H
#define NabaL_Ast_CVariableDeclaration_H

#include "Statement.h"

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
            Tk::Sp<NabaIr::CTypeManager> typeManager,
            NabaIr::CBlockBuilder& blockBuilder,
            Tk::SpList<const NabaIr::CFunction>& functions
            )const override;

private:
    Tk::Sp<const CIdentifier> 
        m_type;
    
    Tk::Sp<const CIdentifier> 
        m_id;
    
    Tk::Sp<const CExpression> 
        m_assignmentExpr;
};}


#endif