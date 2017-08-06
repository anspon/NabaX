#include "TkPch.h"
#include "FilePosition.h"

namespace Tk
{

//--------------------------------------------------------------------------------------------------
CFilePosition::CFilePosition(
    const filesystem::path& completePathFile,
    unsigned int line,
    unsigned int col
    ):
    m_completePathFile(completePathFile),
    m_line(line),
    m_col(col)
{
}
//--------------------------------------------------------------------------------------------------
const filesystem::path& CFilePosition::CompletePathFile(
    )const
{
    return m_completePathFile;
}
//--------------------------------------------------------------------------------------------------
unsigned int CFilePosition::Line(
    )const
{
    return m_line;
}
//--------------------------------------------------------------------------------------------------
unsigned int CFilePosition::Col(
    )const
{
    return m_col;
}

}