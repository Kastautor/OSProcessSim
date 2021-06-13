#ifndef INSTRUCTIONBLOCK_H
#define INSTRUCTIONBLOCK_H

#include "instructionitem.h"

class InstructionBlock : public InstructionItem
{
public:
    InstructionBlock();
    virtual void step() override;
    void blockResource();
};

#endif // INSTRUCTIONBLOCK_H
