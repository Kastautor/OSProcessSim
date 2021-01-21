#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <process.h>

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

    void on_processButton_clicked();

private:
    Ui::MainWindow *ui;
    std::queue<Process*> processes;
    Process *SelectedProcess;
};
#endif // MAINWINDOW_H
