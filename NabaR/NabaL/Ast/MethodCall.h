#ifndef NabaL_Ast_CMethodCall_H
#define NabaL_Ast_CMethodCall_H

#include "Expression.h"

namespace Ast
{
class CIdentifier;
class CExpression;

class CMethodCall : public CExpression 
{
public:
    CMethodCall(
        const CIdentifier* id, 
        const Tk::SpList<const CExpression>* arguments
        ) ;
    
private:
    Tk::Sp<const CIdentifier>
        m_id;

    Tk::SpList<const CExpression>
        m_arguments;

};
}


#endif