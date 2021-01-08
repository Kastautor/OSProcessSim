#include "processgraph.h"
#include <QGraphicsView>
#include <QLabel>
#include <QGraphicsScene>
#include "instructionitem.h"

ProcessGraph::ProcessGraph(int index, QWidget * parent)
    :QFrame(parent)
{
    //setStyleSheet("border: 2px solid blue");
    QLabel *label = new QLabel(QString::number(index), this);
    label->show();

    QGraphicsView *view = new QGraphicsView(this);

    QGraphicsScene *scene = new QGraphicsScene(0, 0, 100, 500);

    InstructionItem *instruction = new InstructionItem;
    scene->addItem(instruction);


    view->setScene(scene);
    view->show();
}

ProcessGraph::~ProcessGraph()
{

}

void ProcessGraph::paintEvent(QPaintEvent *event)
{

}
