#ifndef NabaIr_CBlock_H
#define NabaIr_CBlock_H

namespace Naba
{
namespace Ir
{
class CVariable;
class CInstruction;

class CBlock
{
public:
    CBlock(
        const Tk::SpList<const CVariable>& variables,
        const Tk::SpList<const CInstruction>& instructions
        );
    ~CBlock();

    const Tk::SpList<const CVariable>& 
        Variables(
            )const;

    const Tk::SpList<const CInstruction>& 
        Instructions(
            )const;
private:
    const Tk::SpList<const CVariable> 
        m_variables;

    const Tk::SpList<const CInstruction>
        m_instructions;

};

}
}

#endif