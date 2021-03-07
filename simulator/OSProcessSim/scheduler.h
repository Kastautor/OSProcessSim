#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <iostream>
#include "processitem.h"

class Scheduler
{
public:
    Scheduler(QString, QList<ProcessItem *>);
    QString step();
    ProcessItem *getCurrentProcess();
    int getTotalCycles() const;
    int getCycles() const;
private:
    void selectNextProcess();
    QString algorithm;
    QList<ProcessItem *> processes;
    ProcessItem *currentProcess;
};

#endif // SCHEDULER_H
