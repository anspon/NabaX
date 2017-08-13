#ifndef Naba_Lng_Ast_CFunctionParameter_H
#define Naba_Lng_Ast_CFunctionParameter_H

#include "Node.h"

namespace Naba
{
namespace Lng
{

namespace Ast
{
class CIdentifier;
class CExpression;

class CFunctionParameter : public CNode
{
public:
    CFunctionParameter(
        const CIdentifier* type, 
        const CIdentifier* id
        );

public:
    Tk::Sp<const CIdentifier> 
        m_type;
    
    Tk::Sp<const CIdentifier> 
        m_id;
};

}
}
}


#endif