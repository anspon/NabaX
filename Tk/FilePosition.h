#ifndef CFilePosition_H
#define CFilePosition_H

namespace Tk
{

class CFilePosition
{
public:
        CFilePosition(
            const filesystem::path& completePathFile,
            unsigned int line,
            unsigned int col
            );

    const filesystem::path& 
        CompletePathFile(
            )const;

    unsigned int 
        Line(
            )const;
    
    unsigned int 
        Col(
            )const;

private:
    const filesystem::path 
        m_completePathFile;
    
    unsigned int 
        m_line;
    
    unsigned int 
        m_col;

};

}

#endif