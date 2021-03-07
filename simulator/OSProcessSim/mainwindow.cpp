#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <processitem.h>
#include "configuration.h"
#include "xmlmanager.h"

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
        selectedProcessItem->addInstructionItem(new InstructionItem(InstructionTypes::Operation));
    }
}

void MainWindow::on_addProcessButton_clicked()
{
    // Add a new process
    ProcessItem *pI = new ProcessItem(this);
    ui->programsArea->layout()->addWidget(pI);

    // Connect mousepress event
    QObject::connect(pI, SIGNAL(sendSelection(ProcessItem*)), this, SLOT(selectProcess(ProcessItem*)));
}

void MainWindow::selectProcess(ProcessItem *pI)
{
    // Set the selected process
    selectedProcessItem = pI;

    // Obtain the list of ProcessItems
    QList<ProcessItem *> processItems = ui->programsArea->findChildren<ProcessItem *>();

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

/*!
 * \brief MainWindow::on_saveButton_clicked
 */
void MainWindow::on_saveButton_clicked()
{

}

void MainWindow::on_removeInstructionButton_clicked()
{
    if (selectedInstructionItem != 0){
        delete selectedInstructionItem;
        selectedInstructionItem = 0;
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

    XMLManager XMLmanager(config);
}
