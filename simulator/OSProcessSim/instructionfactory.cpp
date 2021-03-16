#include "instructionfactory.h"
#include "instructionload.h"
#include "instructionsave.h"
#include "instructionoperation.h"

//enum InstructionTypes { Operation, Load, Save};

InstructionFactory::InstructionFactory()
{

}

InstructionItem* InstructionFactory::createInstruction(InstructionTypes type)
{
    if (type == Operation)
        return new InstructionOperation();
    if (type == Load)
        return new InstructionLoad();
    if (type == Save)
        return new InstructionSave();
}
