#ifndef XMLMANAGER_H
#define XMLMANAGER_H

#include "pugixml.hpp"
#include "configuration.h"

using namespace pugi;

class XMLManager
{
public:
    XMLManager();
    void createProcessNode(ProcessItem* p, xml_node node);
    void createInstructionNode();
    void save(Configuration configuration, QString filePath);
    Configuration* load(QString filePath, QWidget * parent);

private:
    xml_document doc;
    Configuration configuration;
};

#endif // XMLMANAGER_H
