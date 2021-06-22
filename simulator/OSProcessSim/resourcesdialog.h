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
    explicit ResourcesDialog(bool linker, QWidget *parent = nullptr);
    ~ResourcesDialog();
    Resource* getSelectedResource();

private slots:
    void on_addButton_clicked();
    void on_deleteButton_clicked();
    void on_okButton_clicked();

private:
    Ui::ResourcesDialog *ui;
    void updateDatabase();
    Resource* selectedResource = NULL;
};

#endif // RESOURCESDIALOG_H
