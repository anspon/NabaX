#ifndef Naba_Lng_Ast_CLiteral_H
#define Naba_Lng_Ast_CLiteral_H


#include "Expression.h"

namespace Naba
{
namespace Lng
{
namespace Ast
{
class CLiteral : public CExpression
{
public:
        CLiteral(
            const StringToken* stringToken
            );

private:
    std::string 
        m_originalText;    

};

}
}
}


#endif