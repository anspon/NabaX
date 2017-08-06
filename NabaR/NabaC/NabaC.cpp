{
    
}
#include "NabaCPch.h"

#include "NabaL/ParseModule.h"
#include "NabaL/TranslationUnit.h"
#include "NabaL/Module.h"
#include "NabaL/CompileError.h"
#include "NabaIr/Backends/CodeStreamer.h"
#include "NabaIr/Module.h"
#include "NabaIr/TranslationUnit.h"
#include "NabaIr/Function.h"
#include "NabaIr/StandardType.h"
#include "NabaIr/TypeManager.h"
#include "NabaIr/Parameter.h"

#include "NabaIr/Backends/Cpp/CppGen.h"

#include "Tk/Exception.h"
#include "Tk/FilePosition.h"

static void PrintError(
    Tk::Sp<const NabaL::CCompileError> error
    )
{
    if( error->FilePosition() )
    {
        std::cout << error->FilePosition()->CompletePathFile() << "(" << error->FilePosition()->Line() << ")" << ": ";
    }

    std::cout << "Error " << (int)error->Code() << ": " << error->Text() << std::endl;
}
//--------------------------------------------------------------------------------------------------
void ErrorCheckModuleThrow(Tk::Sp<const NabaL::CModule> astModule )
{
    bool hasErrors = false;
    for( Tk::Sp<const NabaL::CTranslationUnit> translationUnit : astModule->TranslationUnits() )
    {
            
        for( Tk::Sp<const NabaL::CCompileError> error : translationUnit->Errors() )
        {
            PrintError( error );
            hasErrors = true;
        }
    }
    if( hasErrors )
    {
        TK_ASSERT( !hasErrors, "Errors found during compilation, aborting" );
    }
}


class CType
{
public:
    CType(        
        const std::string& name,
        const std::string& fullyQualifiedName
        ):
        m_name(name),
        m_fullyQualifiedName(fullyQualifiedName)
    {
        
    }

    const std::string&
        Name(
            )const
    {
        return m_name;
    }

private:
    const std::string
        m_name;

    const std::string
        m_fullyQualifiedName;
};
//--------------------------------------------------------------------------------------------------
class CCoreType : public CType
{
    using BaseClass = CType;
public:
    CCoreType(        
        const std::string& name
        ):
        BaseClass(name, name)
    {
    }

    
};

class CStruct  : public CType
{
    using BaseClass = CType;
public:
    CStruct(        
        const std::string& name
        ):
        BaseClass(name, name)
    {
    }
    
};
//--------------------------------------------------------------------------------------------------
Tk::SpList<const CType> ResolveTypes(
    Tk::Sp<const NabaL::CModule> astModule 
    )
{
    Tk::SpList<const CType> allTypes;
    
    allTypes.push_back( Tk::MakeSp<CCoreType>("i32") );
    allTypes.push_back( Tk::MakeSp<CCoreType>("i64") );
    allTypes.push_back( Tk::MakeSp<CCoreType>("double") );

    Tk::SpList<const NabaL::CCompileError> allErrors;

    bool hasErrors = false;
    for( Tk::Sp<const NabaL::CTranslationUnit> translationUnit : astModule->TranslationUnits() )
    {
        const Tk::Sp<const Ast::CNode> ast = translationUnit->Ast();
        if( translationUnit->Errors().size() )
        {
            for( Tk::Sp<const NabaL::CCompileError> error : translationUnit->Errors() )
            {
                allErrors.push_back(error);
            }
        }
    }

    for( Tk::Sp<const NabaL::CCompileError> error : allErrors )
    {
        PrintError( error );
    }

    return allTypes;
}
//--------------------------------------------------------------------------------------------------
int main(int argv, char** argc)
{
    
    try
    {
        TK_ASSERT( 2 == argv, "invalid number of arguments provided" );

        std::string sourceDirectory = argc[1];

        Tk::Sp<const NabaL::CModule> astModule = NabaL::ParseModule(sourceDirectory);
        ErrorCheckModuleThrow(astModule);

        ResolveTypes(astModule);


//        BuildAllTypes(astModule);

        filesystem::directory_iterator sourceIterator(argc[1]);
        TK_ASSERT( filesystem::directory_iterator() != sourceIterator, "Invalid source directory '" << argc[1] << "' ");

        filesystem::path buildPath(sourceDirectory);
        filesystem::path filePath = buildPath /= "HelloWorld.cpp";
        CStreamT<std::ofstream> targetFile( filePath );
        CCodeStreamer streamer(targetFile);

        
        Tk::Sp<const NabaIr::CTypeManager> irTypeManager = NabaIr::CTypeManager::Construct();

        Tk::Sp<NabaIr::CFunction> irFunctionMain = 
            Tk::MakeSp<NabaIr::CFunction>(
                "MyFirstFunction",
                Tk::SpList<const NabaIr::CParameter>
                    {
                        irTypeManager->MakeStandardParameter(NabaIr::stInt32, "parameter1"),
                        irTypeManager->MakeStandardParameter(NabaIr::stInt64, "parameter2"),
                        irTypeManager->MakeStandardParameter(NabaIr::stInt64, "parameter3")
                    }
                );

        Tk::SpList<const NabaIr::CFunction> irFunctions = { irFunctionMain };

        Tk::Sp<NabaIr::CTranslationUnit> irUnitMain = Tk::MakeSp<NabaIr::CTranslationUnit>("Main", irFunctions);
        Tk::SpList<const NabaIr::CTranslationUnit> irUnits = { irUnitMain };

        Tk::Sp<NabaIr::CModule> irModule = Tk::MakeSp<NabaIr::CModule>("HelloWorld", irUnits);
        
        NabaIr::Backends::CppGen::Stream(irModule, streamer );

        streamer << "int main(int argv, const char** argc ){return 0;}";

//        node->MakeCpp(streamer);
    }
    catch( Tk::CException& e )
    {
        std::cout << e.Message() << std::endl;
        std::cin.get();
    }
    return 0;
}

