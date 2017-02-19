#ifndef NabaL_Ast_CFunctionParameter_H
#define NabaL_Ast_CFunctionParameter_H

#include "Statement.h"

namespace Ast
{
class CIdentifier;
class CExpression;

class CFunctionParameter : public CStatement 
{
public:

    CFunctionParameter(
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