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
    Configuration(QMap<QString, QMap<QString, QString>> map, QString algorithm);
    QMap<QString, QMap<QString, QString>> getProcesses();
    QString getAlgorithm();
private:
    QMap<QString, QMap<QString, QString>> processes;
    QString algorithm;
};

#endif // CONFIGURATION_H
