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

    connect(this->view, SIGNAL(clicked(QModelIndex)), this, SLOT(selectResource(QModelIndex)));
}

ResourcesController::~ResourcesController()
{

}

void
ResourcesController::selectResource(const QModelIndex q)
{
    QStringList list = model->stringList();
    QString name = list.at(q.row());
    Resource* r = resourcesDB->getResource(name);

    emit sendResource(r);
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

    // Get the
}

void
ResourcesController::add(QString name)
{
    if (name.isEmpty())
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
    }
    else
    {
        Resource* r = new Resource(name);
        resourcesDB->addResource(r);
    }
    updateView();
}

void
ResourcesController::add(Resource* resource)
{
    if (resource != NULL)
    {
        resourcesDB->addResource(resource);
    }
    updateView();
}

void
ResourcesController::remove()
{
    QModelIndexList selected = view->selectionModel()->selectedIndexes();
    foreach(QModelIndex elem, selected)
    {
        // Remove from DB
        resourcesDB->remResource(model->stringList().at(elem.row()));
    }
    updateView();
}

Resource*
ResourcesController::getSelectedResource()
{
    QModelIndexList selected = view->selectionModel()->selectedIndexes();
    foreach(QModelIndex elem, selected)
    {
        QString rName = model->stringList().at(elem.row());
        return resourcesDB->getResource(rName);
    }

    //updateView();
}

void
ResourcesController::unlink()
{

    updateView();
}
