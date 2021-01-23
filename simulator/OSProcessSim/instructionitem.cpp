#include "instructionitem.h"
#include <QCursor>
#include <QPainter>

InstructionItem::InstructionItem(InstructionTypes type)
{

    setCursor(Qt::OpenHandCursor);
}

void InstructionItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QPen(Qt::black, 3));
    painter->drawRoundedRect(5, 5, 90, 50, 1, 1);
}

QRectF InstructionItem::boundingRect() const
{
    return QRectF(-15.5, -15.5, 34, 34);
}
