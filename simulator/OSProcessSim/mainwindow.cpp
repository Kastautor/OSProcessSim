#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <processitem.h>
#include "configuration.h"
#include "xmlmanager.h"
#include "instructionoperation.h"
#include "instructionsave.h"
#include "instructionload.h"
#include "instructionlock.h"
#include <qmessagebox.h>
#include "resourcescontroller.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    const int nAlgorithms = 3;
    // Add the scheduler algorithm options
    std::string Algorithms[nAlgorithms] = {"FCFS", "SFJ", "SRTN"};
    for (int i = 0; i <= nAlgorithms-1; i++)
    {
        ui->algorithmSelector->addItem(QString::fromStdString(Algorithms[i]));
    }

    // Resources database
    resourcesController = new ResourcesController(ui->resourcesListView);

    // Set programsArea layout
    ui->programsArea->setLayout(new QHBoxLayout(this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sumButton_clicked()
{
    // Selected process
    if (selectedProcessItem != 0)
    {
        selectedProcessItem->addInstructionItem(new InstructionOperation());
    }
}

void MainWindow::on_loadButton_clicked()
{
    // Selected process
    if (selectedProcessItem != 0)
    {
        selectedProcessItem->addInstructionItem(new InstructionLoad());
    }
}

/*!
 * \brief MainWindow::on_saveButton_clicked
 */
void MainWindow::on_saveButton_clicked()
{
    // Selected process
    if (selectedProcessItem != 0)
    {
        selectedProcessItem->addInstructionItem(new InstructionSave());
    }
}

void MainWindow::on_addLockInstructionButton_clicked()
{
    // Selected process
    if (selectedProcessItem != 0)
    {
        selectedProcessItem->addInstructionItem(new InstructionLock());
    }
}

void MainWindow::on_addProcessButton_clicked()
{
    // Add a new process
    addProcess(NULL);
}

void MainWindow::addProcess(ProcessItem* p)
{
    ProcessItem *pI;
    if (p == NULL)
        // Create a new process
        pI = new ProcessItem();
    else
        pI = p;

    // Add the selected process
    ui->programsArea->layout()->addWidget(pI);

    // Connect mousepress event
    QObject::connect(pI, SIGNAL(sendSelection(ProcessItem*)), this, SLOT(selectProcess(ProcessItem*)));
}


void MainWindow::selectProcess(ProcessItem *pI)
{
    // Set the selected process
    selectedProcessItem = pI;

    // Obtain the list of ProcessItems
    QList<ProcessItem *> processItems = getProcesses();

    // Highlight the selected process
    for (int i = 0; i < processItems.size(); i++)
    {
        ProcessItem *pICurrent = processItems.at(i);
        if (pICurrent == pI){
            pICurrent->highlight(true);
        }else{
            pICurrent->highlight(false);
        }
    }
}

void MainWindow::on_removeProcessButton_clicked()
{
    if (selectedProcessItem != 0)
    {
        delete selectedProcessItem;
        selectedProcessItem = 0;
    }
}

void MainWindow::on_beginButton_clicked()
{
    QString algorithm = ui->algorithmSelector->currentText();

    // Reset all processes
    foreach(ProcessItem *process, getProcesses())
        process->reset();

    // Pass the processes to the scheduler
    scheduler = new Scheduler(algorithm, getProcesses());


    ui->beginButton->setEnabled(false);
    ui->stepButton->setEnabled(true);
    ui->totalCyclesLabel->setText("Steps: " + QString::number(scheduler->getCycles()) + " / " + QString::number(scheduler->getTotalCycles()));
    this->setVisible(false);
    this->setVisible(true);
}

void MainWindow::on_stepButton_clicked()
{
    QString status = scheduler->step();
    selectProcess(scheduler->getCurrentProcess());

    if(status.compare("finished") == 0){
        ui->beginButton->setEnabled(true);
        ui->stepButton->setEnabled(false);
        QMessageBox msg(this);
        msg.setText("All processed have finished");
        msg.exec();
        qDebug("All programs are finished");
    }
    ui->totalCyclesLabel->setText("Steps: " + QString::number(scheduler->getCycles()) + " / " + QString::number(scheduler->getTotalCycles()));

    this->setVisible(false);
    this->setVisible(true);
}

void MainWindow::on_removeInstructionButton_clicked()
{

    if (selectedProcessItem != 0){
        selectedProcessItem->removeSelectedInstruction();
    }
}

QList<ProcessItem *> MainWindow::getProcesses() const
{
    return ui->programsArea->findChildren<ProcessItem *>();
}

void MainWindow::on_configSaveButton_clicked()
{
    // Temporary save in a predefined .xml file for development purpose
    // To be replaced by a file selection dialog
    QString algorithm = ui->algorithmSelector->currentText();
    Configuration config = getConfiguration();

    XMLManager xmlManager;
    xmlManager.save(config, "./config2.xml");
}

void MainWindow::on_configLoadButton_clicked()
{
    // Clear current config
    clear();
    XMLManager xmlManager;
    Configuration* config = xmlManager.load("/media/david/Datos/Documentos/Proyecto/OSProcessSim/simulator/OSProcessSim/config.xml");

    // Load processes from file
    QMap<QString, QMap<QString, QList<QString>>> processes = config->getProcesses();

    foreach(QString pName, processes.keys())
    {
        ProcessItem* pI = new ProcessItem(pName);
        QMap<QString, QList<QString>> p = processes.value(pName);
        foreach(QString iName, p.keys())
        {
            QList<QString> i = p.value(iName);
            InstructionTypes type;
            QList<Resource*> resources;
            for (int index = 0; index < p.size(); index++)
            {
                if (index == 0)
                {
                    // Sets instructiontype
                    type = InstructionTypes::Load;
                }
                else
                {
                    // Sets resources
                    Resource* r = new Resource(i.at(index));
                    resources.append(r);
                }
            }
            // Create instruction
            InstructionItem* iI = new InstructionItem(type, iName);
            // Add resources to instruction
            foreach(Resource* r, resources)
                iI->addResource(r);
            // Add instruction to process
            pI->addInstructionItem(iI);
        }
        // Add process to configuration
        addProcess(pI);
    }
    repaint();
}

void
MainWindow::clear()
{
    // Clear all process
    QList<ProcessItem *> processItems = getProcesses();
    foreach(ProcessItem* p, processItems)
        delete p;

    selectedInstructionItem = NULL;
    selectedProcessItem = NULL;
}

void
MainWindow::on_addResourceButton_clicked()
{
    resourcesController->add();
}


void
MainWindow::on_removeResourceButton_clicked()
{
    resourcesController->remove(getConfiguration());
}


void
MainWindow::on_linkResourceButton_clicked()
{
    Resource* r = resourcesController->getSelectedResource();
    if (r != NULL && selectedInstructionItem != NULL)
    {
        selectedInstructionItem->addResource(r);
    }
}

Configuration
MainWindow::getConfiguration()
{
    QMap<QString, QMap<QString, QList<QString>>> map;
    // Each process
    foreach(ProcessItem* p, getProcesses())
    {
        // Each instruction
        QMap<QString, QList<QString>> processMap;
        foreach(InstructionItem* i, p->getInstructions())
        {
            QList<QString> instructionMap;
            instructionMap.append(InstructionTypeStrings[0]);
            // Each resource
            foreach(Resource* r, i->getResources())
                instructionMap.append(r->getName());
            // Add instructions to process
            processMap.insert(i->getName(), instructionMap);
        }
        map.insert(p->getName(), processMap);
    }

    return Configuration(map, ui->algorithmSelector->currentText());
}
