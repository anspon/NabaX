#include "NabaLPch.h"

#include "Identifier.h"

namespace Ast
{
CIdentifier::CIdentifier(
    const std::string* name
    ) : m_name(*name) 
{
    delete name; 
}

}

