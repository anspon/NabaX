#ifndef Naba_Lng_ParseModule_H
#define Naba_Lng_ParseModule_H

#include "NabaL/NabaLPchHeaders.h"

namespace Naba
{ 
namespace Lng 
{
namespace Ast
{
class CModule;

Tk::Sp<const CModule>
    ParseModule(
        const std::string& sourceFolder
        );

}
}
}

#endif