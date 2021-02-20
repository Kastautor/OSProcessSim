#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <iostream>
#include "processitem.h"

class Scheduler
{
public:
    Scheduler(std::string, QList<ProcessItem *>);
    std::string step();
    ProcessItem *getCurrentProcess();
    int getTotalCycles() const;
    int getCycles() const;
private:
    void selectNextProcess();
    std::string algorithm;
    QList<ProcessItem *> processes;
    ProcessItem *currentProcess;
};

#endif // SCHEDULER_H
