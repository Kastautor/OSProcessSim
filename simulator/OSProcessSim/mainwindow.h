#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <processitem.h>

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

private:
    Ui::MainWindow *ui;
    ProcessItem *selectedProcessItem = 0;
};
#endif // MAINWINDOW_H
