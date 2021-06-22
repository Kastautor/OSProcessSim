#ifndef INSTRUCTIONLOCK_H
#define INSTRUCTIONLOCK_H
#include "instructionitem.h"

class InstructionLock : public InstructionItem
{
public:
    InstructionLock();
    virtual void step() override;
};

#endif // INSTRUCTIONLOCK_H
