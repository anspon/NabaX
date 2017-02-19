#ifndef NabaL_Ast_CStructVariableDeclaration_H
#define NabaL_Ast_CStructVariableDeclaration_H

#include "StructPart.h"

namespace Ast
{
class CIdentifier;
class CExpression;

class CStructVariable : public CStructPart
{
public:

    CStructVariable(
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
};
}


#endif