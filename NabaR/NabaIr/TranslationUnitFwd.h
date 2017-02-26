#ifndef TranslationUnitFwd_H
#define TranslationUnitFwd_H


class CTranslationUnit;

namespace TranslationUnit
{
    using SharedPtr = std::shared_ptr<CTranslationUnit>;
    using ListT = std::list<SharedPtr>;
}



#endif