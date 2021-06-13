#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include "processitem.h"
#include "resourcesdatabase.h"

/*!
 * \brief Internal representation of the simulation inputs
 */
class Configuration
{
public:
    Configuration();
    Configuration(QList<ProcessItem *> processes, QString algorithm);
    QList<ProcessItem*> getProcesses();
    QString getAlgorithm();
private:
    QList<ProcessItem*> processes;
    QString algorithm;
};

#endif // CONFIGURATION_H
