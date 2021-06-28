#include "resourcescontroller.h"
#include <QListView>
#include <QStringListModel>
#include <QInputDialog>
#include "resourcesdatabase.h"
#include <QMessageBox>

ResourcesController::ResourcesController(QListView* view)
{
    // Sets the resources model (database) and view
    this->view = view;
    this->resourcesDB = new ResourcesDataBase();

    model = new QStringListModel();
    view->setModel(model);
}

ResourcesController::~ResourcesController()
{

}

void
ResourcesController::updateView()
{
    QStringList list;
    foreach(Resource* r, ResourcesDataBase::getResources())
    {
        list << r->getName();
    }
    model->setStringList(list);
}

void
ResourcesController::add()
{
    // Launchs a dialog to insert name
    QInputDialog d;
    int accept = d.exec();
    if (accept != 0 && !d.textValue().isEmpty())
    {
        // Adds to DB
        Resource* r = new Resource(d.textValue());
        resourcesDB->addResource(r);
    }
    updateView();
}

void
ResourcesController::remove(Configuration config)
{
    QModelIndexList selected = view->selectionModel()->selectedIndexes();
    foreach(QModelIndex elem, selected)
    {
        // Remove from DB
        resourcesDB->remResource(model->stringList().at(elem.row()));
    }
    updateView();
}

void
ResourcesController::link()
{

    updateView();
}

void
ResourcesController::unlink()
{

    updateView();
}
