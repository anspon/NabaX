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
        Tk::Sp<CTypeManager> typeManager
        );
    
    Tk::Sp<const CBlock> 
        Flush(
            )const;

    Tk::Sp<const CVariable>
        AddLocalVariable(
            const std::string& typeName,
            const std::string& variableName
            );

    Tk::Sp<const CVariable>
        GetVariable(
            const std::string& variableName
            );

    Tk::Sp<const CVariable>
        AddVariable(
            const std::string& typeName,
            const std::string& variableName
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
            const std::string& functionName,
            const Tk::SpList<const CVariable>& parameters
            );
    void
        While(
            Tk::Sp<const CVariable> variable,
            Tk::Sp<const CBlock> block
            );

private:
    Tk::SpMap<std::string, const CVariable>
        m_variables;

    Tk::SpList<const CVariable>
        m_localVariables;

    Tk::SpList<const CInstruction>
        m_instructions;

    Tk::Sp<CTypeManager> 
        m_typeManager;
};


}

#endif