#include "processitem.h"
#include <QGraphicsView>
#include "instructionitem.h"

ProcessItem::ProcessItem(QWidget * parent)
    :QFrame(parent)
{
    currentInstruction = 0;

    // Set the panel dimensions
    this->setFixedSize(100, 500);
    this->setFrameStyle(QFrame::Box);

    //Set vertical layout
    layout = new QVBoxLayout();
    this->setLayout(layout);

    //layout->addWidget(new QPushButton("1"));
    //layout->addWidget(new QPushButton("2"));
    layout->addItem(new QSpacerItem(0,500,QSizePolicy::Expanding));
}

ProcessItem::~ProcessItem()
{

}

void ProcessItem::addInstructionItem(InstructionItem *iI)
{
    //QList<QPushButton *> instructionItems = this->findChildren<QPushButton *>();
    // Connect instruction to be selectable
    connect(iI, SIGNAL(sendSelection(InstructionItem*)), this, SLOT(selectInstruction(InstructionItem*)));
    layout->insertWidget(layout->count()-1, iI);
    paintEvent(nullptr);
}

QList<InstructionItem *> ProcessItem::getInstructions() const
{
    QList<InstructionItem *> instructionItems = findChildren<InstructionItem *>();
    return instructionItems;
}

void ProcessItem::highlight(bool b)
{
    if (b)
    {
        this->setLineWidth(2);
    }else
    {
        this->setLineWidth(1);
    }
}

void ProcessItem::mousePressEvent(QMouseEvent *event)
{
    emit sendSelection(this);
}

bool ProcessItem::isFinished()
{
    bool allFinished = true;

    // Obtain the list of instruction items
    foreach (InstructionItem *item, getInstructions())
    {
        allFinished = allFinished && item->isFinished();
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
    repaint();
}

void ProcessItem::selectNextInstruction()
{
    // Obtain the list of instruction items
    foreach (InstructionItem *item, getInstructions())
    {
        if(!item->isFinished()){
            currentInstruction = item;
            currentInstruction->highlight(true);
        }
    }
}

int ProcessItem::getTotalCycles() const
{
    int totalCycles = 0;
    foreach (InstructionItem *item, getInstructions())
        totalCycles += item->getTotalCycles();

    return totalCycles;
}

int ProcessItem::getCycles() const
{
    int cycles = 0;
    foreach (InstructionItem *item, getInstructions())
        cycles += item->getCycles();

    return cycles;
}

void ProcessItem::reset()
{
    QList<InstructionItem *> instructionItems = getInstructions();
    foreach(InstructionItem *item, instructionItems)
        item->reset();
}

void ProcessItem::removeSelectedInstruction()
{
    if (selectedInstruction != 0)
    {
        delete selectedInstruction;
        selectedInstruction = 0;
    }
}


void
ProcessItem::selectInstruction(InstructionItem* iI)
{
    // Set the selected instruction
    selectedInstruction = iI;

    // Obtain the list of instructions
    QList<InstructionItem*> instructionItems = getInstructions();

    // Highlight the selected instruction
    for (int i = 0; i < instructionItems.size(); i++)
    {
        InstructionItem *iICurrent = instructionItems.at(i);
        if (iICurrent == iI){
            iICurrent->highlight(true);
        }else{
            iICurrent->highlight(false);
        }
    }

    // Select this process
    emit sendSelection(this);
}

