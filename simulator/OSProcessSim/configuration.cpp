#include "configuration.h"

Configuration::Configuration()
{

}

Configuration::Configuration(QMap<QString, QMap<QString, QList<QString>>> processes, QString algorithm)
{
    this->processes = processes;
    this->algorithm = algorithm;
}

QMap<QString, QMap<QString, QList<QString>>>
Configuration::getProcesses()
{
    return processes;
}

QString Configuration::getAlgorithm()
{
    return algorithm;
}
