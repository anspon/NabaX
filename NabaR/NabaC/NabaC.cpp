{
    
}
#include "NabaCPch.h"

#include "NabaL/ParseModule.h"
#include "NabaL/TranslationUnit.h"
#include "NabaL/Module.h"
#include "NabaL/CompileError.h"

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

private:
    const std::string
        m_name;
    const std::string
        m_fullyQualifiedName;
};


//--------------------------------------------------------------------------------------------------
int main(int argv, char** argc)
{
    
    try
    {
        TK_ASSERT( 2 == argv, "invalid number of arguments provided" );

        std::string sourceDirectory = argc[1];

        Tk::Sp<const NabaL::CModule> astModule = NabaL::ParseModule(sourceDirectory);
        ErrorCheckModuleThrow(astModule);

//        BuildAllTypes(astModule);



/*
        filesystem::directory_iterator sourceIterator(argc[1]);
        TK_ASSERT( filesystem::directory_iterator() != sourceIterator, "Invalid source directory '" << argc[1] << "' ");

        filesystem::path buildPath(argc[2]);

        filesystem::path outputPath = buildPath /= "HelloWorld";

        if(!filesystem::exists(outputPath ) )
        {
            bool created = filesystem::create_directory(outputPath);
            TK_ASSERT( created, "Failed to create output directory '" << outputPath << "'" );
        }

        for( const filesystem::directory_entry& entry : sourceIterator )
        {
            const filesystem::path& path = entry.path();
        
            if( std::string(".aspp") == path.extension() )
            {
                filesystem::path filePath = outputPath /= path.stem();
                filePath.replace_extension("cpp");
                CStreamT<std::ofstream> targetFile( filePath );

                int i=0;i++;
                std::string completeText;
                {            
                    std::ifstream inFile( path );
                    TK_ASSERT( !inFile.bad(), "Unable to open file '" << path << "'" );
                    char line[1000] = {0};
                    while( inFile.getline(line, 999) )
                    {
                        completeText += line + std::string("\n");
                    }
                }
                if( sp<const Ast::CNode> node = getAST(completeText.c_str() ) )
                {
                    
                    CCodeStreamer streamer(targetFile);
                    node->MakeCpp(streamer);
                    int i=0; i++;
                }
            }        
        }
        */

    }
    catch( Tk::CException& e )
    {
        std::cout << e.Message() << std::endl;
        std::cin.get();
    }
    return 0;
}

