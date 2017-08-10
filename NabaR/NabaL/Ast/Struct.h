#ifndef Naba_Lng_Ast_CStruct_H
#define Naba_Lng_Ast_CStruct_H

#include "NabaLPchHeaders.h"

#include "Statement.h"

namespace Naba
{
namespace Lng
{
namespace Ast
{
class CIdentifier;
class CStructPart;

class CStruct : public CStatement
{
public:
    CStruct(
        const CIdentifier* name,
        const Tk::SpList<const CStructPart>* list 
        );

private:
    Tk::Sp<const CIdentifier>
        m_name;

    Tk::SpList<const CStructPart>
        m_parts;
};

}
}
}


#endif