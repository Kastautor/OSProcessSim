#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <processitem.h>
#include "scheduler.h"
#include "resourcesdatabase.h"
#include "resourcescontroller.h"
#include "configuration.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_sumButton_clicked();
    void on_addProcessButton_clicked();
    void selectProcess(ProcessItem*);
    void on_removeProcessButton_clicked();
    void on_beginButton_clicked();
    void on_stepButton_clicked();

    void on_saveButton_clicked();

    void on_removeInstructionButton_clicked();

    void on_configSaveButton_clicked();

    void on_loadButton_clicked();

    void on_configLoadButton_clicked();

    void on_addLockInstructionButton_clicked();

    void on_addResourceButton_clicked();

    void on_removeResourceButton_clicked();

    void on_linkResourceButton_clicked();

    void highLightLinkedInstructions(Resource* resourceName);

private:
    void addProcess(ProcessItem* p);
    void clear();
    QList<ProcessItem *> getProcesses() const;
    Configuration getConfiguration();
    void linkResourceToInstruction(QString, InstructionItem*);

    Ui::MainWindow *ui;
    ProcessItem *selectedProcessItem = NULL;
    InstructionItem *selectedInstructionItem = NULL;
    Scheduler *scheduler;
    ResourcesController* resourcesController;
};
#endif // MAINWINDOW_H
