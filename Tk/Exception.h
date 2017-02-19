#ifndef Tk_CException_H
#define Tk_CException_H

namespace Tk
{
class CException
{
public:
        CException(
            const std::string& text 
            );

    const std::string&
        Message(
                )const;
        

private:
    std::string 
        m_text;
};

}

#define TK_ASSERT( condition, text )\
    if(!(condition) ){ std::stringstream stream; stream << text; throw Tk::CException(stream.str());}



#endif