#include "instruction.h"

Instruction::Instruction()
{

}

InstructionItem* Instruction::getGraphicalItem()
{
    // Create the graphical representation for the instruction
    return new InstructionItem();
}
