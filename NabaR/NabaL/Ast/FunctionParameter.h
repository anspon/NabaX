#ifndef Naba_Lng_Ast_CFunctionParameter_H
#define Naba_Lng_Ast_CFunctionParameter_H

#include "Statement.h"

namespace Naba
{
namespace Lng
{

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

public:
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