#ifndef INSTRUCTIONOPERATION_H
#define INSTRUCTIONOPERATION_H
#include "instructionitem.h"

class InstructionOperation : public InstructionItem
{
public:
    InstructionOperation(InstructionTypes type, QWidget * parent = 0);
};

#endif // INSTRUCTIONOPERATION_H
