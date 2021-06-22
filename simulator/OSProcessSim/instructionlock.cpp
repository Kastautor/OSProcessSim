#include "instructionlock.h"

InstructionLock::InstructionLock()
    : InstructionItem(Lock)
{
    totalCycles = 1;
}

void
InstructionLock::step()
{
    InstructionItem::step();
    resource->lock();
}
