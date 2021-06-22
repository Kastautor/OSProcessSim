#include "scheduler.h"

Scheduler::Scheduler(QString algorithm, QList<ProcessItem *> processes)
{
    // Set the scheduler algorithm
    this->algorithm = algorithm;
    this->processes = processes;
    currentProcess = 0;
}

QString Scheduler::step()
{
    // Current process
    if (currentProcess == 0 || currentProcess->isFinished()){
        selectNextProcess();
    }else{
        currentProcess->step();
    }

    // If no processes are pending
    if(currentProcess == 0){
        return "finished";
    }else{
        return "in process";
    }
}

void Scheduler::selectNextProcess()
{
    // Select next process
    // FCFS method
    for (int i = 0; i < processes.size(); i++){
        ProcessItem *p = processes.at(i);
        if (!p->isFinished()){
            currentProcess = p;
            return;
        }else{
            currentProcess = 0;
        }
    }
}

ProcessItem * Scheduler::getCurrentProcess()
{
    return currentProcess;
}

int Scheduler::getTotalCycles() const
{
    int totalCycles = 0;

    foreach(ProcessItem *p, processes)
        totalCycles += p->getTotalCycles();

    return totalCycles;
}

int Scheduler::getCycles() const
{
    int cycles = 0;
    foreach(ProcessItem *p, processes)
        cycles += p->getCycles();

    return cycles;
}
