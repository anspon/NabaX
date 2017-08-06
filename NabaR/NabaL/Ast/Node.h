#ifndef Imdr_Ast_H
#define Imdr_Ast_H

struct CPosition
{
    CPosition(
        unsigned int lineNbr = 0
        )
    {
        m_lineNbr = lineNbr;
    }
    unsigned int m_lineNbr = 0;
};

struct StringToken
{
std::string m_string;
CPosition m_position;
};


namespace Ast
{

class CNode 
{
public:
    virtual ~CNode();

    const CPosition&
        Position(
            )const;

protected:
    CPosition
        m_position;
};
}
#endif
