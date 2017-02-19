#ifndef CModule_H
#define CModule_H

#include "TranslationUnitFwd.h"

namespace Module
{
class CModule
{
public:
    CModule();
    ~CModule();
private:
    TranslationUnit::ListT
        m_translationUnitList;
};

}

#endif