#include "instructionfactory.h"
#include "instructionload.h"
#include "instructionsave.h"
#include "instructionoperation.h"
#include "instructionlock.h"

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
    if (type == Lock)
        return new InstructionLock();
    return NULL;
}
