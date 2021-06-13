#ifndef RESOURCESDIALOG_H
#define RESOURCESDIALOG_H

#include <QDialog>
#include "resourcesdatabase.h"

namespace Ui {
class ResourcesDialog;
}

class ResourcesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ResourcesDialog(QWidget *parent = nullptr);
    ~ResourcesDialog();

private slots:
    void on_addButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::ResourcesDialog *ui;
    ResourcesDataBase* db;
    void updateDatabase();
};

#endif // RESOURCESDIALOG_H
