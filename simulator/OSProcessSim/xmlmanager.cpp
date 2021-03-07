#include "xmlmanager.h"
#include "pugixml.hpp"


XMLManager::XMLManager(Configuration configuration)
{
    xml_document doc;

    xml_node node = doc.append_child(("program"));

    //QList<ProcessItem*>
    foreach(ProcessItem* p, configuration.getProcesses())

    node = node.append_child(("process1"));
    xml_node descr = node.append_child("description");
    node = node.append_child(("process1"));

    doc.save_file("/media/david/Datos/Documentos/Proyecto/OSProcessSim/simulator/OSProcessSim/config.xml");

}


xml_node XMLManager::createProcessNode(ProcessItem* p)
{
    xml_node node;
    node.set_name("hola");
    return node;
}

xml_node XMLManager::createInstructionNode()
{
    xml_node node;
    return node;
}
