#ifndef NabaIr_CBlockBuilder_H
#define NabaIr_CBlockBuilder_H

namespace NabaIr
{
class CBlock;
class CVariable;
class CInstruction;
class CTypeManager;
class CFunction;
class CLiteral;

class CBlockBuilder
{
public:
    CBlockBuilder(
        Tk::Sp<const CTypeManager> typeManager
        );
    
    Tk::Sp<const CBlock> 
        Flush(
            )const;

    Tk::Sp<const CVariable>
        AddInt32(
            const std::string& name
            );
    
    Tk::Sp<const CVariable>
        AddInt64(
            const std::string& name
            );

    void
        ZeroVariable(
            Tk::Sp<const CVariable> variable
            );

    void
        AssignVariable(
            Tk::Sp<const CVariable> lhs,
            Tk::Sp<const CVariable> rhs
            );
    void
        AssignLiteral(
            Tk::Sp<const CVariable> lhs,
            Tk::Sp<const CLiteral> rhs
            );
    
    void
        IncrementVariable(
            Tk::Sp<const CVariable> lhs,
            Tk::Sp<const CVariable> rhs
            );
    void
        IncrementLiteral(
            Tk::Sp<const CVariable> lhs,
            Tk::Sp<const CLiteral> rhs
            );
    void
        CallFunction(
            Tk::Sp<const CFunction> function,
            const Tk::SpList<const CVariable>& parameters
            );
    void
        While(
            Tk::Sp<const CVariable> variable,
            Tk::Sp<const CBlock> block
            );

protected:
    Tk::Sp<const CVariable>
        MakeInt32(
            const std::string& name
            );
    
    Tk::Sp<const CVariable>
        MakeInt64(
            const std::string& name
            );
private:
    Tk::SpList<const CVariable>
        m_variables;

    Tk::SpList<const CInstruction>
        m_instructions;

    Tk::Sp<const CTypeManager> 
        m_typeManager;
};


}

#endif