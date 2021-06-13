#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <processitem.h>
#include "configuration.h"
#include "xmlmanager.h"
#include "instructionoperation.h"
#include "instructionsave.h"
#include "instructionload.h"
#include "resourcesdialog.h"

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
        pI = new ProcessItem(this);
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
    Configuration config(getProcesses(), algorithm);

    XMLManager xmlManager;
    xmlManager.save(config, "/media/david/Datos/Documentos/Proyecto/OSProcessSim/simulator/OSProcessSim/config.xml");
}

void MainWindow::on_configLoadButton_clicked()
{
    // Clear current config
    clear();
    XMLManager xmlManager;
    Configuration* config = xmlManager.load("/media/david/Datos/Documentos/Proyecto/OSProcessSim/simulator/OSProcessSim/config.xml");

    // Load processes from file
    foreach(ProcessItem* p, config->getProcesses())
        addProcess(p);

    repaint();
}

void MainWindow::clear()
{
    // Clear all process
    QList<ProcessItem *> processItems = getProcesses();
    foreach(ProcessItem* p, processItems)
        delete p;

    selectedInstructionItem = NULL;
    selectedProcessItem = NULL;
}



void MainWindow::on_resourcesButton_clicked()
{
    if (resourcesDB == NULL)
        resourcesDB = new ResourcesDataBase();
    // Launch the dialog to edit the resources
    ResourcesDialog* dia = new ResourcesDialog(resourcesDB);
    dia->exec();
}

