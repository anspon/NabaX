#ifndef NabaIr_CppGen_H
#define NabaIr_CppGen_H


namespace NabaIr
{

namespace Backends
{
namespace CppGen
{
void 
    Stream(
        Tk::Sp<const CModule> module, 
        CCodeStreamer& stream
        );
}
}
}


#endif