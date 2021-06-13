#include "resourcesdialog.h"
#include "ui_resourcesdialog.h"
#include <QInputDialog>

ResourcesDialog::ResourcesDialog(ResourcesDataBase* db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResourcesDialog)
{
    this->db = db;

    ui->setupUi(this);
}

ResourcesDialog::~ResourcesDialog()
{
    delete ui;
}

void ResourcesDialog::on_addButton_clicked()
{
    QInputDialog d(this);
    int ok = d.exec();
    if (ok != 0)
    {
        QString name(d.textValue());
        Resource* r = new Resource(name);
        db->addResource(r);

    }
    updateDatabase();
}

void
ResourcesDialog::updateDatabase()
{
    ui->listWidget->clear();
    foreach(Resource* r, db->getResources())
    {
        QString name = r->getName();
        ui->listWidget->addItem(name);
    }
}


void ResourcesDialog::on_deleteButton_clicked()
{
    QList<QListWidgetItem*> selectedItems = ui->listWidget->selectedItems();
    if (!selectedItems.isEmpty())
    {
        foreach(QListWidgetItem* item, selectedItems)
        {
            db->remResource(item->text());
        }
    }
    updateDatabase();
}

