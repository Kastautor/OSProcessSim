#ifndef RESOURCESDATABASE_H
#define RESOURCESDATABASE_H

#include "resource.h"
#include <QMap>

class ResourcesDataBase
{
public:
    ResourcesDataBase();
    QMap<QString, Resource*> getResources();
    void addResource(Resource* r);
    void remResource(Resource* r);
    void remResource(QString name);
    bool findResource(QString name, Resource* r);

private:
    QMap<QString, Resource*> resources;
};

#endif // RESOURCESDATABASE_H
