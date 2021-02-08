#ifndef INSTRUCTIONITEM_H
#define INSTRUCTIONITEM_H

#include <QGraphicsItem>
#include <instruction.h>
#include <QMouseEvent>

enum InstructionTypes { Operation, Load, Save};

class InstructionItem : public QGraphicsObject
{
public:
    InstructionItem(InstructionTypes type, QWidget * parent = 0);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void step();
    bool isFinished();
    void highlight(bool);
    InstructionItem* getSelectedInstructionItem();
signals:
    void sendSelection(InstructionItem*);
protected:
    QColor color;
    InstructionTypes type;
    int totalCycles;
    int cycle;
    bool selected;
};

#endif // INSTRUCTIONITEM_H
