#ifndef RESOURCE_H
#define RESOURCE_H
#include <QList>

class Resource
{
public:
    Resource(QString name);
    void lock();
    void release();
    QString getName();

private:
    QString name;
    bool locked;
};

#endif // RESOURCE_H
