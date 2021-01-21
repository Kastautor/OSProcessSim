#include "processitem.h"
#include <QGraphicsView>
#include "instructionitem.h"
#include <iostream>

ProcessItem::ProcessItem(QWidget * parent)
    :QFrame(parent)
{
    // Create graphical view
    view = new QGraphicsView(this);
    scene = new QGraphicsScene(0, 0, 100, 500);
    view->setScene(scene);
    view->show();
}

ProcessItem::~ProcessItem()
{

}

void ProcessItem::addInstructionItem(InstructionItem *iI)
{
    scene->addItem(iI);
}

void ProcessItem::paintEvent(QPaintEvent *event)
{

}

void ProcessItem::mousePressEvent(QMouseEvent *event)
{

}

void ProcessItem::highlight(){
    // Code to highlight the process and select it
    QRectF border = scene->sceneRect();
    QPen pen(Qt::blue);
    pen.setWidth(2);
    scene->addRect(border, pen);
}
