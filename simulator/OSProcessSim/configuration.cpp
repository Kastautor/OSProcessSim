#include "configuration.h"

Configuration::Configuration()
{

}

/*!
 * \brief Configuration::Configuration
 * \param processes
 * \param algorithm
 */
Configuration::Configuration(QList<ProcessItem *> processes, QString algorithm)
{
    this->processes = processes;
    this->algorithm = algorithm;
}

QList<ProcessItem*> Configuration::getProcesses()
{
    return this->processes;
}

QString Configuration::getAlgorithm()
{
    return algorithm;
}
