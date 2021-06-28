#ifndef XMLMANAGER_H
#define XMLMANAGER_H

#include "pugixml.hpp"
#include "configuration.h"

using namespace pugi;

class XMLManager
{
public:
    XMLManager();
    void createProcessNode(QString pName, QMap<QString, QList<QString>> p, xml_node node);
    void createInstructionNode(QString iName, QList<QString> i, xml_node node);
    void save(Configuration configuration, QString filePath);
    Configuration* load(QString filePath);

private:
    xml_document doc;
    Configuration configuration;
};

#endif // XMLMANAGER_H
