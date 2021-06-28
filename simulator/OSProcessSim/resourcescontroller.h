#ifndef RESOURCESCONTROLLER_H
#define RESOURCESCONTROLLER_H

#include <QWidget>
#include <QListView>
#include "resourcesdatabase.h"
#include <QStringListModel>
#include "processitem.h"
#include "configuration.h"

class ResourcesController : public QObject
{

public:
    ResourcesController(QListView* view);
    ~ResourcesController();
private:
    QListView* view;
    ResourcesDataBase* resourcesDB;
    QStringListModel* model;

    void updateView();

public:
    void add(QString name = "");
    void remove(Configuration config);
    Resource* getSelectedResource();
    void unlink();
};

#endif // RESOURCESCONTROLLER_H
