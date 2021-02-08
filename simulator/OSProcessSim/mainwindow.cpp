#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <processitem.h>

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
    std::string algorithm = ui->algorithmSelector->currentText().toStdString();
    // Pass the processes to the scheduler
    std::list<Process*> processes;

    QList<ProcessItem *> processItems = ui->programsArea->findChildren<ProcessItem *>();
    scheduler = new Scheduler(algorithm, processItems);
    ui->beginButton->setEnabled(false);
    ui->stepButton->setEnabled(true);
    this->setVisible(false);
    this->setVisible(true);
}

void MainWindow::on_stepButton_clicked()
{
    std::string status = scheduler->step();
    if(status.compare("finished") == 0){
        ui->beginButton->setEnabled(true);
        ui->stepButton->setEnabled(false);
    }
    this->setVisible(false);
    this->setVisible(true);
}

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
