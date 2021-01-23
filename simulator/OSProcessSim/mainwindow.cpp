#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <processitem.h>
#include <borrar.h>

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
    selectedProcessItem->addInstructionItem(new InstructionItem(InstructionTypes::Operation));
}

void MainWindow::on_addProcessButton_clicked()
{
    // Add a new process
    ProcessItem *pI = new ProcessItem(this);
    processItems.push(pI);
    ui->programsArea->layout()->addWidget(pI);

    // Connect mousepress event
    QObject::connect(pI, SIGNAL(sendSelection(ProcessItem*)), this, SLOT(selectProcess(ProcessItem*)));
}

void MainWindow::selectProcess(ProcessItem *pI)
{
    selectedProcessItem = pI;

    for (int i = 1; i <= processItems.size(); i++)
    {
        ProcessItem *pICurrent = processItems.front();
        if (pICurrent == pI){
            pICurrent->highlight(true);
        }else{
            pICurrent->highlight(false);
        }
        processItems.pop();
        processItems.push(pICurrent);
    }
}

void MainWindow::on_removeProcessButton_clicked()
{
    for (int i = 1; i <= processItems.size(); i++)
    {
        ProcessItem *pICurrent = processItems.front();
        processItems.pop();
        if (pICurrent != selectedProcessItem){
            processItems.push(pICurrent);
        }
    }
}
