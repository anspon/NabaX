#ifndef Naba_Lng_Cst_CompileAstModule_H
#define Naba_Lng_Cst_CompileAstModule_H


namespace Naba
{
namespace Lng
{
namespace Ast
{
class CModule;
}

namespace Cst
{
class CModule;

Tk::Sp<const CModule> 
    CompileAstModule(
        Tk::Sp<const Ast::CModule> astModule
        );
}
}
}




#endif
