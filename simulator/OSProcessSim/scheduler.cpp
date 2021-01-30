#include "scheduler.h"

Scheduler::Scheduler(std::string algorithm, QList<ProcessItem *> processes)
{
    // Set the scheduler algorithm
    this->algorithm = algorithm;
    this->processes = processes;
    currentProcess = 0;
}

std::string Scheduler::step()
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

void Scheduler::selectNextProcess(){
    // Select next process
    // FCFS method
    for (int i = 0; i < processes.size(); i++){
        ProcessItem *p = processes.at(i);
        if (!p->isFinished()){
            currentProcess = p;
            p->highlight(true);
        }else{
            currentProcess = 0;
        }
    }
}
