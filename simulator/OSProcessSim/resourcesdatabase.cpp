#include "resourcesdatabase.h"

ResourcesDataBase::ResourcesDataBase()
{


}

///
/// \brief ResourcesDataBase::resources initialization
///
QMap<QString, Resource*> ResourcesDataBase::resources;

bool
ResourcesDataBase::contains(QString name)
{
    return resources.contains(name);
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
ResourcesDataBase::remResource(QString name)
{
    resources.remove(name);
}

Resource*
ResourcesDataBase::getResource(QString name)
{
    return resources.value(name);
}
