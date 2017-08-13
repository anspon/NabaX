#ifndef Naba_Lng_Ast_CBlockPart_H
#define Naba_Lng_Ast_CBlockPart_H

#include "Node.h"

namespace Naba
{
namespace Lng
{
namespace Ast
{

enum eBlockPartType
{
    bptBlock,
    bptVariableDeclaration,
    bptFunctionDeclaration,
    bptStruct,
    bptExpressionStatement,
    bptAssignement,
    bptWhile,
    bptFor
};

class CBlockPart : public CNode 
{
public:
        CBlockPart(
            eBlockPartType blockPartType
            );
    

    eBlockPartType 
        BlockPartType(
            )const;

    const eBlockPartType 
        m_blockPartType;
};

}
}
}


#endif