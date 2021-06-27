#ifndef RESOURCESCONTROLLER_H
#define RESOURCESCONTROLLER_H

#include <QListView>
#include "resourcesdatabase.h"

class ResourcesController
{
public:
    ResourcesController(QListView* view, ResourcesDataBase* resourcesDB);
private:
    QListView* view;
    ResourcesDataBase* resourcesDB;
};

#endif // RESOURCESCONTROLLER_H
