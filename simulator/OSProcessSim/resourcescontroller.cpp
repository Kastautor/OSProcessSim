#include "resourcescontroller.h"

ResourcesController::ResourcesController(QListView* view, ResourcesDataBase* resourcesDB)
{
    // Sets the resources model (database) and view
    this->view = view;
    this->resourcesDB = resourcesDB;
}
