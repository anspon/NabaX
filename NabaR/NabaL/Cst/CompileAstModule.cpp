#include "NabaLPch.h"
#include "CompileAstModule.h"

#include "NabaL/Ast/TranslationUnit.h"
#include "NabaL/Ast/Module.h"
#include "NabaL/Ast/Block.h"
#include "NabaL/Ast/Struct.h"

#include "Impl/TypeManager.h"

namespace Naba
{
namespace Lng
{
namespace Cst
{
Tk::Sp<const CModule> 
    CompileAstModule(
        Tk::Sp<const Ast::CModule> astModule
        )
{
    Impl::CTypeManager typeManager;

    for( Tk::Sp<const Ast::CTranslationUnit> astTranslationUnit : astModule->TranslationUnits() )
    {
        Tk::Sp<const Ast::CBlock> ast = astTranslationUnit->Ast();
//        ForEachBlockRecursive(ast);
        ast->ForEachBlock(
            [&]( Tk::Sp<const Ast::CBlock> astBlock )
            {
                            
            }
        );
    }
    return Tk::Sp<const CModule>();
}
}
}
}


