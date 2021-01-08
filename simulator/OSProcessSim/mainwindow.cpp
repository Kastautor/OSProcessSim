#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <processgraph.h>

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

}

void MainWindow::on_processButton_clicked()
{
    ProcessGraph *process = new ProcessGraph(processes.size()+1, ui->programsArea);
    ui->programsArea->layout()->addWidget(process);
    processes.insert(std::make_pair(processes.size()+1, process));
    process->show();
}
