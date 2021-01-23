#include "processitem.h"
#include <QGraphicsView>

ProcessItem::ProcessItem(QWidget * parent)
    :QFrame(parent)
{
    // Initialize queue
    instructionItems = new std::queue<InstructionItem*>();

    // Set the panel dimensions
    this->setFixedSize(100, 500);

    // Create graphical view
    view = new QGraphicsView(this);
    scene = new QGraphicsScene(0, 0, 100, 500);

    highlight(false);

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
    // Create graphical representation
    for (int l = 1; instructionItems->size(); l++)
    {
        // Add all instruction graphical items
        InstructionItem *iI = instructionItems->front();
        addInstructionItem(iI);
    }
}

void ProcessItem::mousePressEvent(QMouseEvent *event)
{
    emit sendSelection(this);
}

void ProcessItem::highlight(bool b){
    // Code to highlight the process and select it
    border = new QRectF(scene->sceneRect());
    QPen pen;
    pen.setWidth(4);
    if (b){
        pen.setColor(Qt::blue);
        //scene->setBackgroundBrush(Qt::red);
    }else{
        pen.setColor(Qt::black);
        //scene->setBackgroundBrush(Qt::blue);
    }
    scene->addRect(*border, pen);
}
