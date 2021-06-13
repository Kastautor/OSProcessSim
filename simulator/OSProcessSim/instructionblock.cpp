#include "instructionblock.h"

InstructionBlock::InstructionBlock()
    : InstructionItem(Save)
{

}

void
InstructionBlock::step()
{
    InstructionItem::step();

}

void
InstructionBlock::blockResource()
{

}
