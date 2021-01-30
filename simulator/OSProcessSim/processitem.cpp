#include "processitem.h"
#include <QGraphicsView>
#include "instructionitem.h"

ProcessItem::ProcessItem(QWidget * parent)
    :QFrame(parent)
{
    currentInstruction = 0;

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
    instructionItems.append(iI);
    paintEvent(nullptr);
}

void ProcessItem::paintEvent(QPaintEvent *event)
{
    // Obtain the list of instruction items
    for (int l = 0; l < instructionItems.size(); l++)
    {
        // Add all instruction graphical items
        InstructionItem *iI = instructionItems.at(l);
        iI->setPos(0, l*100);
        scene->addItem(iI);
    }
}

void ProcessItem::mousePressEvent(QMouseEvent *event)
{
    emit sendSelection(this);
}

void ProcessItem::highlight(bool b)
{
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

bool ProcessItem::isFinished()
{
    bool allFinished = true;
    for(int i = 0; i < instructionItems.size(); i++){
        allFinished = allFinished && instructionItems.at(i)->isFinished();
    }
    return allFinished;
}

std::string ProcessItem::step()
{
    if (currentInstruction == 0 || currentInstruction->isFinished()){
        selectNextInstruction();
    }else{
        currentInstruction->step();
    }

    // If no instructions are pending
    if(currentInstruction == 0){
        return "finished";
    }else{
        return "in process";
    }
}

void ProcessItem::selectNextInstruction()
{
    for (int i = 0; i < instructionItems.size(); i++){
        InstructionItem *ins = instructionItems.at(i);
        if(!ins->isFinished()){
            currentInstruction = ins;
            currentInstruction->highlight(true);
        }
    }
}


