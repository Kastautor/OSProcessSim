#include "resourcesdialog.h"
#include "ui_resourcesdialog.h"
#include <QInputDialog>
#include <QMessageBox>

ResourcesDialog::ResourcesDialog(bool linker, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResourcesDialog)
{
    ui->setupUi(this);
    if (!linker)
    {
        ui->okButton->hide();
    }
    updateDatabase();
}

ResourcesDialog::~ResourcesDialog()
{
    delete ui;
}

void
ResourcesDialog::on_addButton_clicked()
{
    QInputDialog d(this);
    d.setTextValue("A");
    int ok = d.exec();

    QString name = d.textValue();
    if (ResourcesDataBase::contains(name))
    {
        QMessageBox msg;
        msg.setText("This resource already exists. Provide a new name.");
        msg.exec();
        return;
    }

    if (ok != 0)
    {
        QString name(d.textValue());
        Resource* r = new Resource(name);
        ResourcesDataBase::addResource(r);

    }
    updateDatabase();
}

void
ResourcesDialog::updateDatabase()
{
    ui->listWidget->clear();
    foreach(Resource* r, ResourcesDataBase::getResources())
    {
        QListWidgetItem* i = new QListWidgetItem();
        i->setText(r->getName());
        if(r == selectedResource)
            i->setBackground(QColor(Qt::green));
        ui->listWidget->addItem(i);
    }
}


void
ResourcesDialog::on_deleteButton_clicked()
{
    QList<QListWidgetItem*> selectedItems = ui->listWidget->selectedItems();
    if (!selectedItems.isEmpty())
    {
        foreach(QListWidgetItem* item, selectedItems)
        {
            ResourcesDataBase::remResource(item->text());
        }
    }
    updateDatabase();
}

void
ResourcesDialog::on_okButton_clicked()
{
    QList<QListWidgetItem*> selectedItems = ui->listWidget->selectedItems();
    if (!selectedItems.empty())
    {
        selectedResource = ResourcesDataBase::getResource(selectedItems.at(0)->text());
    }
    updateDatabase();
}

Resource*
ResourcesDialog::getSelectedResource()
{
    return selectedResource;
}
