#ifndef INSTRUCTIONITEM_H
#define INSTRUCTIONITEM_H

#include <QGraphicsItem>
#include <instruction.h>

enum InstructionTypes { Operation, Load, Save};

class InstructionItem : public QGraphicsObject
{
public:
    InstructionItem(InstructionTypes type);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QColor color;
    //Instruction instruction;
};

#endif // INSTRUCTIONITEM_H
