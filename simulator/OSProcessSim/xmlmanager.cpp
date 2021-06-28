#include "xmlmanager.h"
#include "pugixml.hpp"
#include "string"
#include <qdebug.h>
#include "instructionload.h"
#include "instructionfactory.h"

XMLManager::XMLManager()
{
}


void XMLManager::createProcessNode(QMap<QString, QList<QString>> p, xml_node node)
{
    foreach(QString iName, p.keys())
    {
        std::string str = "Instruction";
        xml_node instruction = node.append_child(str.c_str());
        instruction.append_attribute("name") = iName.toStdString().c_str();
        createInstructionNode(p.value(iName), node);
    }
}

void XMLManager::createInstructionNode(QList<QString> i, xml_node node)
{
    for (int index = 0; index < i.size(); index++)
    {
       if(index == 0)
       {
           std::string str = "Type";
           xml_node resource = node.append_child(str.c_str());
           resource.append_attribute("name") = i.at(0).toStdString().c_str();
        }
       else
       {
           std::string str = "Resource";
           xml_node resource = node.append_child(str.c_str());
           resource.append_attribute("name") = i.at(0).toStdString().c_str();
       }
    }
}

void XMLManager::save(Configuration configuration, QString filePath)
{
    xml_document doc;

    xml_node configNode = doc.append_child("program");
    configNode.append_attribute("algorithm") = configuration.getAlgorithm().toStdString().c_str();

    QMap<QString, QMap<QString, QList<QString>>> processes = configuration.getProcesses();
    foreach(QString pName, processes.keys())
    {
        QMap<QString, QList<QString>> p = processes.value(pName);
        std::string str = "Process";
        configNode = configNode.append_child(str.c_str());
        createProcessNode(p, configNode);
        // Return pointer to parent
        configNode = configNode.parent();
    }

    //xml_node descr = node.append_child("description");
    //node = node.append_child(("instruction"));

    doc.save_file(filePath.toStdString().c_str());
}

Configuration*
XMLManager::load(QString filePath)
{
    // Processes list
    QMap<QString, QList<QString>> processes;

    // XML parser
    xml_document doc;
    pugi::xml_parse_result result = doc.load_file(filePath.toStdString().c_str());

    pugi::xml_node nodeConfiguration = doc.first_child();

    for (pugi::xml_node nodeProcess: nodeConfiguration.children())
    {
        QMap<QString, QList<QString>> process;

        for (pugi::xml_node nodeInstruction: nodeProcess.children())
        {
            xml_attribute attr = nodeInstruction.first_attribute();
            InstructionItem* instruction = InstructionFactory::createInstruction(InstructionTypes(QString(attr.value()).toUInt()));
            qDebug() << "Instruction: "<< instruction->getType();
            //process->addInstructionItem(instruction);
        }

        // Add process to configuration
        //processes.append(process);
    }

    //Configuration* configuration = new Configuration(processes, "");
    return NULL;
}

