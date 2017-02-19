#ifndef NabaL_Ast_CBlock_H
#define NabaL_Ast_CBlock_H

#include "Expression.h"

namespace Ast
{
class CBlockPart;

class CBlock : public CExpression 
{
public:
    void
        AddBlockPart(
            const CBlockPart* part
            );

private:        
    Tk::SpList<const CBlockPart>
        m_blockParts;
};

}


#endif