#ifndef NabaL_Ast_CDouble_H
#define NabaL_Ast_CDouble_H

#include "Literal.h"

namespace Ast
{
class CDouble : public CLiteral
{
using BaseClass = CLiteral;
public:
    CDouble(
        const StringToken* stringToken
        );

    Tk::Sp<const NabaIr::CVariable>
        MakeExpressionIr(
            Tk::Sp<NabaIr::CTypeManager> typeManager,
            NabaIr::CBlockBuilder& blockBuilder
            )const;
    
       
private:    
    double 
        m_value;

};

}


#endif