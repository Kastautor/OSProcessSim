#include "instructionlock.h"
#include <QMessageBox>

InstructionLock::InstructionLock()
    : InstructionItem(Lock)
{
    totalCycles = 1;
}

void
InstructionLock::step()
{
    InstructionItem::step();
    if (resource == NULL)
    {
        QMessageBox msg;
        msg.setText("No resource linked to lock instruction");
        msg.exec();
        return;
    }
    resource->lock();
}
