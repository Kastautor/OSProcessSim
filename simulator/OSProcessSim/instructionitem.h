#ifndef INSTRUCTIONITEM_H
#define INSTRUCTIONITEM_H

#include <QGraphicsItem>

class InstructionItem : public QGraphicsObject
{
public:
    InstructionItem();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QColor color;
};

#endif // INSTRUCTIONITEM_H
