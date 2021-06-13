#include "resourcesdatabase.h"

ResourcesDataBase::ResourcesDataBase()
{


}

QMap<QString, Resource*>
ResourcesDataBase::getResources()
{
    QMap<QString, Resource*> map;
    return map;
}

void
ResourcesDataBase::addResource(Resource* r)
{
    //resources.insert(r->getName(), r);
}

void
ResourcesDataBase::remResource(QString name)
{
    resources.remove(name);
}

