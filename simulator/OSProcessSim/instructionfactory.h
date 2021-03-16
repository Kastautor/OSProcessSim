#ifndef INSTRUCTIONFACTORY_H
#define INSTRUCTIONFACTORY_H

#include "instructionitem.h"


class InstructionFactory
{
public:
    InstructionFactory();
    static InstructionItem* createInstruction(InstructionTypes type);
};

#endif // INSTRUCTIONFACTORY_H
