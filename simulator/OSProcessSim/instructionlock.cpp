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
    if (resources.isEmpty())
    {
        QMessageBox msg;
        msg.setText("No resource linked to lock instruction");
        msg.exec();
        return;
    }

    foreach(Resource* r, resources)
        r->lock();
}
