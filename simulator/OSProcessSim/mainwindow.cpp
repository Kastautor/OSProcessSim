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
    SelectedProcess->addInstruction(nullptr);

    /*
    for (int i = 1; processes.size(); i++){
        Process *process = processes.front();
    }
    */
}

void MainWindow::on_processButton_clicked()
{
    // Add a new process
    Process *p = new Process();
    processes.push(p);

    /*
    ProcessItem *process = new ProcessItem();
    ui->programsArea->layout()->addWidget(process);
    processes.insert(std::make_pair(processes.size()+1, process));
    */
}
