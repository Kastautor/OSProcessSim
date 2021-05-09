#include "instructionitem.h"
#include <QCursor>
#include <QPainter>
#include <QDebug>

InstructionItem::InstructionItem(InstructionTypes type, QWidget * parent)
{
    this->type = type;
    cycles = 0;
    totalCycles = 0;
    selected = false;
    //paint();
}

void
InstructionItem::paint()
{
    setCursor(Qt::OpenHandCursor);
    QPainter *painter = new QPainter();

    this->adjustSize();

    painter->drawRoundedRect(10, 10, 80, 80, 1, 1);
    painter->drawText(30, 30, QString::number(cycles) + " / " + QString::number(totalCycles));
}

void
InstructionItem::step()
{
    cycles++;
}

bool
InstructionItem::isFinished()
{
    if(totalCycles == cycles){
        return true;
    }else{
        return false;
    }
}

void
InstructionItem::highlight(bool b)
{
    QPalette pal = this->palette();

    if (b)
        pal.setColor(QPalette::Button, QColor(Qt::blue));
    else
        pal.setColor(QPalette::Button, QColor(Qt::color0));

    this->setPalette(pal);
}


void
InstructionItem::paintEvent(QPaintEvent *e)
{
    QPushButton::paintEvent(e);
    QPainter painter(this);

    painter.drawText(10, 15, QString::number(cycles) + " / " + QString::number(totalCycles));
    qWarning() << "updating" << this << "paint";
}

int
InstructionItem::getTotalCycles() const
{
    return totalCycles;
}

int
InstructionItem::getCycles() const
{
    return cycles;
}

void
InstructionItem::reset()
{
    cycles = 0;
}

InstructionTypes
InstructionItem::getType()
{
    return type;
}


void
InstructionItem::mousePressEvent(QMouseEvent *event)
{
    emit sendSelection(this);
}
