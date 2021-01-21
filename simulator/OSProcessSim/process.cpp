#include "process.h"

Process::Process()
{
    // Initialize instruction

}

void Process::addInstruction(Instruction *i)
{
    // Add instruction
    instructions.push(i);
}

void Process::removeInstruction(Instruction *i)
{
    // Remove instruction

}

ProcessItem* Process::getGraphicalItem()
{
    // Create graphical representation
    ProcessItem *pI = new ProcessItem();
    for (int l = 1; instructions.size(); l++)
    {
        // Add all instruction graphical items
        Instruction *i = instructions.front();
        InstructionItem *iI = i->getGraphicalItem();
        pI->addInstructionItem(iI);
    }
}
