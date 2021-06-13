#ifndef INSTRUCTIONITEM_H
#define INSTRUCTIONITEM_H

#include <QPushButton>
#include <QMouseEvent>
#include "resource.h"

enum InstructionTypes { Operation, Load, Save};

class InstructionItem : public QPushButton
{
    Q_OBJECT

public:
    InstructionItem(InstructionTypes type);
    virtual void step();
    bool isFinished();
    void highlight(bool);
    InstructionItem* getSelectedInstructionItem();
    int getTotalCycles() const;
    int getCycles() const;
    InstructionTypes getType();
    void reset();
    Resource* getResource();

signals:
    void sendSelection(InstructionItem*);

protected:
    virtual void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseDoubleClickEvent(QMouseEvent *event) override;

    QColor color;
    InstructionTypes type;
    int totalCycles;
    int cycles;
    bool selected;
private:
    void paint();
    Resource* resource;

};

#endif // INSTRUCTIONITEM_H
