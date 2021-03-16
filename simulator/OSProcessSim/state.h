#ifndef STATE_H
#define STATE_H

#include <list>
enum InstructionTypes { Operation, Load, Save};

class State
{
public:
    State();
    void addProgram(int index);
    bool removeProgram(int index);
    void addProgramInstruction(int indexProgram, int indexInstruction, InstructionTypes type);
    bool removeProgramInstruction(int indexProgram, int indexInstruction);

private:
    class Program
    {
        Program();
        void addInstruction(int index);
        bool removeInstruction(int index);
    private:
        class Instruction{
            Instruction();
            void setSteps();
        };
    };

    std::list<Program> programs;
};

#endif // STATE_H
