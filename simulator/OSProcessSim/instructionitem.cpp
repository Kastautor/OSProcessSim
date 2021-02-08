#include "instructionitem.h"
#include <QCursor>
#include <QPainter>

InstructionItem::InstructionItem(InstructionTypes type, QWidget * parent)
{
    setCursor(Qt::OpenHandCursor);
    this->type = type;
    cycle = 0;
    totalCycles = 4;
    selected = false;
}

void InstructionItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    if (selected == true){
        painter->setPen(QPen(Qt::blue, 3));
    }else{
        painter->setPen(QPen(Qt::black, 3));
    }
    painter->drawRoundedRect(10, 10, 80, 80, 1, 1);

    painter->drawText(30, 30, QString::number(cycle) + " / " + QString::number(totalCycles));
}

QRectF InstructionItem::boundingRect() const
{
    return QRectF(-15.5, -15.5, 34, 34);
}

void InstructionItem::step()
{
    cycle++;
}

bool InstructionItem::isFinished()
{
    if(totalCycles == cycle){
        return true;
    }else{
        return false;
    }
}

void InstructionItem::highlight(bool b)
{
    if (b)
        selected = true;
    else
        selected = false;
}


