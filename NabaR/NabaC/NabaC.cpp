#include "NabaCPch.h"

#include "NabaL/Ast/ParseModule.h"
#include "NabaL/Ast/TranslationUnit.h"
#include "NabaL/Ast/Module.h"
#include "NabaL/CompileError.h"
#include "NabaIr/Backends/CodeStreamer.h"
#include "NabaIr/Module.h"
#include "NabaIr/TranslationUnit.h"
#include "NabaIr/Function.h"
#include "NabaIr/StandardType.h"
#include "NabaIr/TypeManager.h"
#include "NabaIr/Parameter.h"
#include "NabaIr/Variable.h"
#include "NabaIr/Block.h"
#include "NabaIr/Literal.h"
#include "NabaIr/Instruction.h"
#include "NabaIr/BlockBuilder.h"
#include "NabaIr/FunctionBuilder.h"

#include "NabaIr/Backends/Cpp/CppGen.h"

#include "Tk/Exception.h"
#include "Tk/FilePosition.h"

static void PrintError(
    Tk::Sp<const Naba::Lng::CCompileError> error
    )
{
    if( error->FilePosition() )
    {
        std::cout << error->FilePosition()->CompletePathFile() << "(" << error->FilePosition()->Line() << ")" << ": ";
    }

    std::cout << "Error " << (int)error->Code() << ": " << error->Text() << std::endl;
}
//--------------------------------------------------------------------------------------------------
void ErrorCheckModuleThrow(Tk::Sp<const Naba::Lng::Ast::CModule> astModule )
{
    bool hasErrors = false;
    for( Tk::Sp<const Naba::Lng::Ast::CTranslationUnit> translationUnit : astModule->TranslationUnits() )
    {
            
        for( Tk::Sp<const Naba::Lng::CCompileError> error : translationUnit->Errors() )
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
//--------------------------------------------------------------------------------------------------
void ResolveTypes(
    Tk::Sp<const Naba::Lng::Ast::CModule> astModule 
    )
{
    Tk::SpList<const Naba::Lng::CCompileError> allErrors;

    bool hasErrors = false;
    for( Tk::Sp<const Naba::Lng::Ast::CTranslationUnit> translationUnit : astModule->TranslationUnits() )
    {
        const Tk::Sp<const Naba::Lng::Ast::CNode> ast = translationUnit->Ast();
        if( translationUnit->Errors().size() )
        {
            for( Tk::Sp<const Naba::Lng::CCompileError> error : translationUnit->Errors() )
            {
                allErrors.push_back(error);
            }
        }
    }

    for( Tk::Sp<const Naba::Lng::CCompileError> error : allErrors )
    {
        PrintError( error );
    }
}
//--------------------------------------------------------------------------------------------------
int main(int argv, char** argc)
{
    
    try
    {
        TK_ASSERT( 2 == argv, "invalid number of arguments provided" );

        std::string sourceDirectory = argc[1];

        Tk::Sp<const Naba::Lng::Ast::CModule> astModule = Naba::Lng::Ast::ParseModule(sourceDirectory);
        ErrorCheckModuleThrow(astModule);

        ResolveTypes(astModule);

        Tk::Sp<const Naba::Ir::CModule> irModule = astModule->MakeIr();

//        BuildAllTypes(astModule);

        filesystem::directory_iterator sourceIterator(argc[1]);
        TK_ASSERT( filesystem::directory_iterator() != sourceIterator, "Invalid source directory '" << argc[1] << "' ");

        filesystem::path buildPath(sourceDirectory);
        filesystem::path filePath = buildPath /= "HelloWorld.cpp";
        CStreamT<std::ofstream> targetFile( filePath );

        Naba::Ir::Backends::CppGen::Stream(irModule, targetFile );
        targetFile << "int main(int argv, const char** argc ){Main();return 0;}";

//        node->MakeCpp(streamer);
    }
    catch( Tk::CException& e )
    {
        std::cout << e.Message() << std::endl;
        std::cin.get();
    }
    return 0;
}



    /*
        Tk::Sp<const Ir::CTypeManager> irTypeManager = Ir::CTypeManager::Construct();
        
        Tk::SpList<const Ir::CFunction> irFunctions;
        Tk::Sp<const Ir::CFunction> myFirstFunction;
        {
            Ir::CFunctionBuilder functionBuilder(irTypeManager);

            auto i = functionBuilder.AddInt32("i");
            auto j = functionBuilder.AddInt64("j");

            auto in1 = functionBuilder.AddParameterInt32("in1", Ir::ptIn);

            Tk::Sp<const Ir::CLiteral> irLiteralInt32Zero = 
                Ir::CLiteral::MakeInt32(0);

            Tk::Sp<const Ir::CLiteral> irLiteralInt6455 = 
                Ir::CLiteral::MakeInt64(55);
        
            functionBuilder.ZeroVariable(i);
            functionBuilder.ZeroVariable(j);
            functionBuilder.AssignVariable(i, in1);
            myFirstFunction = functionBuilder.Flush("MyFirstFunction");
            
            irFunctions.push_back(myFirstFunction);
        }
        {
            Ir::CFunctionBuilder functionBuilder(irTypeManager);

            auto i = functionBuilder.AddInt32("i");
            auto j = functionBuilder.AddInt64("j");
            auto k = functionBuilder.AddInt32("k");

            auto loop = functionBuilder.AddInt32("loop");
            functionBuilder.AssignLiteral(loop, Ir::CLiteral::MakeInt32(-10) ) ;

            Ir::CBlockBuilder whileBlock(irTypeManager);
            whileBlock.IncrementLiteral(loop,Ir::CLiteral::MakeInt32(1) );
            functionBuilder.While(loop, whileBlock.Flush() );

            functionBuilder.AssignLiteral(k, Ir::CLiteral::MakeInt32(10) ) ;

            functionBuilder.ZeroVariable(i);
            functionBuilder.ZeroVariable(j);
            
            functionBuilder.AssignLiteral(i, Ir::CLiteral::MakeInt32(33) ) ;
            functionBuilder.AssignLiteral(j, Ir::CLiteral::MakeInt64(55) ) ;

            functionBuilder.IncrementVariable(i, k ) ;

            functionBuilder.CallFunction(myFirstFunction, {i});

            irFunctions.push_back(functionBuilder.Flush("Main"));
        }
        Tk::Sp<Ir::CTranslationUnit> irUnitMain = Tk::MakeSp<Ir::CTranslationUnit>("Main", irFunctions);
        Tk::SpList<const Ir::CTranslationUnit> irUnits = { irUnitMain };

        Tk::Sp<Ir::CModule> irModule = Tk::MakeSp<Ir::CModule>("HelloWorld", irUnits);
        
*/
