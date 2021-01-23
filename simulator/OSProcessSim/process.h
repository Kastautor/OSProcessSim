#ifndef PROCESS_H
#define PROCESS_H
#include <queue>
#include "instruction.h"

class Process
{
public:
    Process();
    void addInstruction(Instruction *i);
    void removeInstruction(Instruction *i);

private:
    std::queue<Instruction*> instructions;
};

#endif // PROCESS_H
