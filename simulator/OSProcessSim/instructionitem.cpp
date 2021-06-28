#include "instructionitem.h"
#include <QCursor>
#include <QPainter>
#include <QDebug>
#include <QUuid>

InstructionItem::InstructionItem(InstructionTypes type)
{
    QUuid id = QUuid::createUuid();
    name = id.toString();
    this->type = type;
    cycles = 0;
    totalCycles = 0;
    selected = false;
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
InstructionItem::paintEvent(QPaintEvent *event)
{
    QPushButton::paintEvent(event);
    QPainter painter(this);

    painter.drawText(10, 15, InstructionTypeStrings[getType()]);
    painter.drawText(10, 30, QString::number(cycles) + " / " + QString::number(totalCycles));
    this->setFixedHeight(40);
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

QList<Resource*>
InstructionItem::getResources()
{
    return resources;
}

QString
InstructionItem::getName()
{
    return name;
}
