#include "NabaLPch.h"
#include "CompileError.h"


namespace NabaL
{
CCompileError::CCompileError(
    eCompileError code,
    const std::string& text,
    Tk::Sp<const Tk::CFilePosition> filePosition
    ):
    m_code(code),
    m_text(text),
    m_filePosition(filePosition)
{
}
//--------------------------------------------------------------------------------------------------
const std::string& CCompileError::Text(
    )const
{
    return m_text;
}
//--------------------------------------------------------------------------------------------------
eCompileError CCompileError::Code(
    )const
{
    return m_code;
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const Tk::CFilePosition> CCompileError::FilePosition(
    )const
{
    return m_filePosition;
}

}