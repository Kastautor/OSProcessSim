#ifndef RESOURCESDATABASE_H
#define RESOURCESDATABASE_H

#include "resource.h"
#include <QMap>

class ResourcesDataBase
{
public:
    ResourcesDataBase();
    static QMap<QString, Resource*> getResources();
    static void addResource(Resource* r);
    static void remResource(QString name);

private:
    static QMap<QString, Resource*> resources;
};

#endif // RESOURCESDATABASE_H
