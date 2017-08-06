#include "NabaIrPch.h"
#include "CodeStreamer.h"

CStream::CEndLine CStream::endl;


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
CStream& operator<<( CStream& stream, int32_t item )
{
    stream.Append(item);
    return stream;
}
//--------------------------------------------------------------------------------------------------
CStream& operator<<( CStream& stream, int64_t item )
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
