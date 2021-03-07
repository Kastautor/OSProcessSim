#ifndef XMLMANAGER_H
#define XMLMANAGER_H

#include "pugixml.hpp"
#include "configuration.h"

using namespace pugi;

class XMLManager
{
public:
    XMLManager(Configuration configuration);
    xml_node createProcessNode(ProcessItem* p);
    xml_node createInstructionNode();
private:
    xml_document doc;
    Configuration configuration;
};

#endif // XMLMANAGER_H
