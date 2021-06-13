#ifndef RESOURCE_H
#define RESOURCE_H
#include <QList>

#include "instructionitem.h"

class Resource
{
public:
    Resource(QString name);
    bool addConstraint(int state, InstructionItem* i);
    void lock(InstructionItem* i);
    void release(InstructionItem* i);
    QString getName();

private:
    QString name;

};

#endif // RESOURCE_H
