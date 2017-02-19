#ifndef NabaL_Ast_CAssignment_H
#define NabaL_Ast_CAssignment_H

#include "Expression.h"

namespace Ast
{
class CIdentifier;

class CAssignment : public CExpression 
{
public:
    CAssignment(
        const CIdentifier* lhs, 
        const CExpression* rhs

        );
private:
    Tk::Sp<const CIdentifier> 
        m_lhs;

    Tk::Sp<const CExpression> 
        m_rhs;

};

}


#endif