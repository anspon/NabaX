#ifndef NabaIr_CVariable_H
#define NabaIr_CVariable_H

namespace NabaIr
{
class CType;

class CVariable
{
public:
    CVariable(
        Tk::Sp<const CType> dataType,
        const std::string& name
        );
    ~CVariable();

    Tk::Sp<const CType> 
        DataType(
            )const;

    const std::string&
        Name(
            )const;

private:
    const Tk::Sp<const CType> 
        m_dataType;

    const std::string 
        m_name;
};

}


#endif