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
    Configuration(QMap<QString, QMap<QString, QList<QString>>> map, QString algorithm);
    QMap<QString, QMap<QString, QList<QString>>> getProcesses();
    QString getAlgorithm();
private:
    QMap<QString, QMap<QString, QList<QString>>> processes;
    QString algorithm;
};

#endif // CONFIGURATION_H
