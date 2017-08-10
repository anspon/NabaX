#ifndef Naba_Lng_CCompileError_H
#define Naba_Lng_CCompileError_H

namespace Tk
{
class CFilePosition;    
}

namespace Naba
{ 
namespace Lng 
{

enum class eCompileError
{
    None = 0,
    SyntaxError = 1,
};

class CCompileError
{
public:
    CCompileError(
        eCompileError code,
        const std::string& text,
        Tk::Sp<const Tk::CFilePosition> filePosition
        );
            
public:
    const std::string&
        Text(
            )const;

    eCompileError 
        Code(
            )const;
        
    Tk::Sp<const Tk::CFilePosition> 
        FilePosition(
            )const;

private:
    eCompileError
        m_code;

    std::string 
        m_text;
       
    unsigned int 
        m_line;

    Tk::Sp<const Tk::CFilePosition>
        m_filePosition;
};

}
}
#endif
