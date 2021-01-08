#ifndef PROCESS_H
#define PROCESS_H
#include <map>
#include <instruction.h>

class Process
{
public:
    Process();
private:
    std::map<int, Instruction> instructions;
};

#endif // PROCESS_H
