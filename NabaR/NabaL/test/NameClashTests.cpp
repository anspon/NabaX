#include "NameClashTests.h"


#include "NabaL/Ast/ParseModule.h"

//--------------------------------------------------------------------------------------------------
TEST_F(CNameClashTests, HelloWorld) 
{
    std::string sourceDirectory = "C:/dev/NabaX/NabaR/NabaL/test/code/NameClashTests/1";

    Tk::Sp<const Naba::Lng::Ast::CModule> astModule = Naba::Lng::Ast::ParseModule(sourceDirectory);

    EXPECT_TRUE(true);
}
//--------------------------------------------------------------------------------------------------
