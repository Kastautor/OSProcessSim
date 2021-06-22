#ifndef RESOURCESDATABASE_H
#define RESOURCESDATABASE_H

#include "resource.h"
#include <QMap>

class ResourcesDataBase
{
public:
    ResourcesDataBase();
    static QMap<QString, Resource*> getResources();
    static bool contains(QString name);
    static void addResource(Resource* r);
    static void remResource(QString name);
    static Resource* getResource(QString name);
    static int getID();

private:
    static QMap<QString, Resource*> resources;
};

#endif // RESOURCESDATABASE_H
