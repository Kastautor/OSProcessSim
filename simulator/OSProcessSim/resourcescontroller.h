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
    Q_OBJECT
public:
    ResourcesController(QListView* view);
    ~ResourcesController();
private:
    QListView* view;
    ResourcesDataBase* resourcesDB;
    QStringListModel* model;

    void updateView();

protected slots:
    void selectResource(const QModelIndex);

signals:
    void sendResource(Resource*);

public:
    void add(QString name = "");
    void add(Resource* resource);
    void remove();
    Resource* getSelectedResource();
    void unlink();
};

#endif // RESOURCESCONTROLLER_H
