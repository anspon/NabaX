#ifndef NabaL_ParseModule_H
#define NabaL_ParseModule_H

#include "NabaLPchHeaders.h"

namespace NabaL
{
class CModule;

Tk::Sp<const CModule>
    ParseModule(
        const std::string& sourceFolder
        );

}

#endif