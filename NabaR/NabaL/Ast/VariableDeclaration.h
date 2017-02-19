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

private:
    Tk::Sp<const CIdentifier> 
        m_type;
    
    Tk::Sp<const CIdentifier> 
        m_id;
    
    Tk::Sp<const CExpression> 
        m_assignmentExpr;
};}


#endif