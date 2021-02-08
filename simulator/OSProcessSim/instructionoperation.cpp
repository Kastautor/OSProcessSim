#include "instructionoperation.h"

InstructionOperation::InstructionOperation(InstructionTypes type, QWidget * parent)
    : InstructionItem(type, parent)
{
    totalCycles = 0;
}
