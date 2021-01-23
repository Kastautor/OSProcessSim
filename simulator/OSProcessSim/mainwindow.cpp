#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <processitem.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
