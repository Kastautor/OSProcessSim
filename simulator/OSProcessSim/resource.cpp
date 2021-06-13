#include "resource.h"

Resource::Resource(QString name)
{
    this->name = name;
}

QString
Resource::getName()
{
    return name;
}

