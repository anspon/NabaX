#include "stdafx.h"
#include "CodeStreamer.h"

CStream::CEndLine CStream::endl;

//--------------------------------------------------------------------------------------------------
CCodeStreamer::CCodeStreamer(
    CStream& stream
    )
    :m_stream(stream)
{
}
//--------------------------------------------------------------------------------------------------
CStream& CCodeStreamer::Stream()
{
    return m_stream;
}
//--------------------------------------------------------------------------------------------------
void CCodeStreamer::BeginStruct(
    const std::string& name
    )
{
    m_stream << 
        "struct" << " " << name << CStream::endl << 
        "{" << CStream::endl;
}
//--------------------------------------------------------------------------------------------------
void CCodeStreamer::EndStruct()
{
    m_stream << "}" << ";" << CStream::endl;
}
//--------------------------------------------------------------------------------------------------
CStream& operator<<( CStream& stream, const char* item )
{
    stream.Append(item);
    return stream;
}
//--------------------------------------------------------------------------------------------------
CStream& operator<<( CStream& stream, const std::string& item )
{
    stream.Append(item);
    return stream;
}
//--------------------------------------------------------------------------------------------------
CStream& operator<<( CStream& stream, const CStream::CEndLine& item )
{
    stream.EndLine();
    return stream;
}


//--------------------------------------------------------------------------------------------------
CCodeStreamer& operator<<( CCodeStreamer& stream, const char* item )
{
    stream.Stream().Append(item);
    return stream;
}
//--------------------------------------------------------------------------------------------------
CCodeStreamer& operator<<( CCodeStreamer& stream, const std::string& item )
{
    stream.Stream().Append(item);
    return stream;
}
//--------------------------------------------------------------------------------------------------
CCodeStreamer& operator<<( CCodeStreamer& stream, const CStream::CEndLine& item )
{
    stream.Stream().EndLine();
    return stream;
}
