#include "xmlmanager.h"
#include "pugixml.hpp"
#include "string"
#include <qdebug.h>
#include "instructionload.h"
#include "instructionfactory.h"

XMLManager::XMLManager()
{
}


void XMLManager::createProcessNode(ProcessItem* p, xml_node node)
{
    foreach(InstructionItem* i, p->getInstructions())
    {
        std::string str = "Instruction";
        xml_node instruction = node.append_child(str.c_str());
        instruction.append_attribute("type") = i->getType();
    }
}

void XMLManager::createInstructionNode()
{
    xml_node node;
}

void XMLManager::save(Configuration configuration, QString filePath)
{
    xml_document doc;

    xml_node configNode = doc.append_child("program");
    configNode.append_attribute("algorithm") = configuration.getAlgorithm().toStdString().c_str();

    //QList<ProcessItem*>
    foreach(ProcessItem* p, configuration.getProcesses())
    {
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

Configuration* XMLManager::load(QString filePath, QWidget* parent)
{
    // Processes list
    QList<ProcessItem *> processes;

    // XML parser
    xml_document doc;
    pugi::xml_parse_result result = doc.load_file(filePath.toStdString().c_str());

    qDebug() << "hola";

    pugi::xml_node nodeConfiguration = doc.first_child();

    for (pugi::xml_node nodeProcess: nodeConfiguration.children())
    {
        ProcessItem* process = new ProcessItem(parent);


        for (pugi::xml_node nodeInstruction: nodeProcess.children())
        {
            xml_attribute attr = nodeInstruction.first_attribute();
            InstructionItem* instruction = InstructionFactory::createInstruction(InstructionTypes(QString(attr.value()).toUInt()));
            qDebug() << "Instruction: "<< instruction->getType();
            process->addInstructionItem(instruction);
        }

        // Add process to configuration
        processes.append(process);
    }

    Configuration* configuration = new Configuration(processes, "");
    return configuration;
}

