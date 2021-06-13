#include "resourcesdatabase.h"

ResourcesDataBase::ResourcesDataBase()
{


}

QMap<QString, Resource*>
ResourcesDataBase::getResources()
{
    return resources;
}

void
ResourcesDataBase::addResource(Resource* r)
{
    resources.insert(r->getName(), r);
}

void
ResourcesDataBase::remResource(Resource* r)
{
    resources.take(r->getName());
}

void
ResourcesDataBase::remResource(QString name)
{
    resources.remove(name);
}

bool
ResourcesDataBase::findResource(QString name, Resource* r)
{

    return true;
}
