#ifndef PROCESS_H
#define PROCESS_H
#include <queue>
#include "instruction.h"
#include "processitem.h"

class Process
{
public:
    Process();
    void addInstruction(Instruction *i);
    void removeInstruction(Instruction *i);
    ProcessItem* getGraphicalItem();

private:
    std::queue<Instruction*> instructions;
};

#endif // PROCESS_H
