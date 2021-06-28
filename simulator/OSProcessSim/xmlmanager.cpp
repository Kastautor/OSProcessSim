#include "xmlmanager.h"
#include "pugixml.hpp"
#include "string"
#include <qdebug.h>
#include "instructionload.h"
#include "instructionfactory.h"

XMLManager::XMLManager()
{
}

void XMLManager::createInstructionNode(QString iName, QList<QString> i, xml_node node)
{
    std::string str = "Instruction";
    xml_node instruction = node.append_child(str.c_str());
    instruction.append_attribute("name") = iName.toStdString().c_str();
    for (int index = 0; index < i.size(); index++)
    {
       if(index == 0)
       {
           std::string str = "Type";
           instruction.append_attribute("Type") = i.at(index).toStdString().c_str();
        }
       else
       {
           std::string str = "Resource";
           xml_node resource = instruction.append_child(str.c_str());
           resource.append_attribute("name") = i.at(index).toStdString().c_str();
       }
    }
}

void
XMLManager::createProcessNode(QString pName, QMap<QString, QList<QString>> p, xml_node node)
{
    std::string str = "Process";
    node = node.append_child(str.c_str());
    node.append_attribute("name") = pName.toStdString().c_str();
    foreach(QString iName, p.keys())
    {
        createInstructionNode(iName, p.value(iName), node);
    }
}

void
XMLManager::save(Configuration configuration, QString filePath)
{
    xml_document doc;

    xml_node node = doc.append_child("program");
    node.append_attribute("algorithm") = configuration.getAlgorithm().toStdString().c_str();

    QMap<QString, QMap<QString, QList<QString>>> processes = configuration.getProcesses();
    foreach(QString pName, processes.keys())
    {
        QMap<QString, QList<QString>> p = processes.value(pName);
        createProcessNode(pName, p, node);
        // Return pointer to parent
        //node = node.parent();
    }

    //xml_node descr = node.append_child("description");
    //node = node.append_child(("instruction"));

    doc.save_file(filePath.toStdString().c_str());
}

Configuration*
XMLManager::load(QString filePath)
{
    // Processes list
    QMap<QString, QMap<QString, QList<QString>>> processes;

    // XML parser
    xml_document doc;
    pugi::xml_parse_result result = doc.load_file(filePath.toStdString().c_str());

    pugi::xml_node nodeConfiguration = doc.first_child();
    QString algorithm = nodeConfiguration.attribute("algorithm").as_string();

    for (pugi::xml_node nodeProcess: nodeConfiguration.children())
    {
        QMap<QString, QList<QString>> instructions;
        QString pName = nodeProcess.first_attribute().as_string();

        for (pugi::xml_node nodeInstruction: nodeProcess.children())
        {
            QList<QString> elems;
            xml_attribute attr = nodeInstruction.attribute("name");
            QString iName = attr.as_string();
            attr = nodeInstruction.attribute("Type");
            QString iType = attr.as_string();
            elems.append(iType);
            for (pugi::xml_node nodeElems: nodeInstruction.children())
            {
                xml_attribute attr = nodeElems.attribute("name");
                QString rName = attr.as_string();
                elems.append(rName);

            }
            // Insert instruction
            instructions.insert(iName, elems);
        }


        // Add process to configuration
        processes.insert(pName, instructions);
    }

    Configuration* configuration = new Configuration(processes, algorithm);
    return configuration;
}

