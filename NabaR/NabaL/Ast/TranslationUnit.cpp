#include "NabaLPch.h"
#include "TranslationUnit.h"
#include "Node.h"
#include "Block.h"

#include "NabaIr/TypeManager.h"
#include "NabaIr/TranslationUnit.h"
#include "NabaIr/BlockBuilder.h"


namespace Naba
{
namespace Lng
{
namespace Ast
{


//--------------------------------------------------------------------------------------------------
CTranslationUnit::CTranslationUnit(
    const std::list<std::string>& nameSpace,
    Tk::Sp<const Ast::CBlock> ast,
    const filesystem::path& completePathFile,
    const Tk::SpList<const CCompileError>& errors
    ):
    m_nameSpace( nameSpace ),
    m_ast( ast ),
    m_completePathFile( completePathFile ),
    m_errors(errors)
{
}
//--------------------------------------------------------------------------------------------------
CTranslationUnit::~CTranslationUnit()
{
}
//--------------------------------------------------------------------------------------------------
const filesystem::path& CTranslationUnit::CompletePathFile()const
{
    return m_completePathFile;
}
//--------------------------------------------------------------------------------------------------
const Tk::SpList<const CCompileError>& CTranslationUnit::Errors()const
{
    return m_errors;
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const Ast::CBlock>  CTranslationUnit::Ast(
    )const
{
    return m_ast;
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const Ir::CTranslationUnit> 
    CTranslationUnit::MakeIr(
    )const
{
    Tk::Sp<Ir::CTypeManager> irTypeManager = Ir::CTypeManager::Construct();
    Tk::SpList<const Ir::CFunction> irFunctions;

    Ir::CBlockBuilder blockBuilder(irTypeManager, nullptr);

    m_ast->MakeIr(irTypeManager, blockBuilder, irFunctions);

    return Tk::MakeSp<Ir::CTranslationUnit>("Main", irFunctions);
}

}
}
}


