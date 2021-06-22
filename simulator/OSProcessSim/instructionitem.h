#ifndef INSTRUCTIONITEM_H
#define INSTRUCTIONITEM_H

#include <QPushButton>
#include <QMouseEvent>
#include "resource.h"

enum InstructionTypes { Operation, Load, Save, Lock};
const QString InstructionTypeStrings[4] = {"Operation", "Load", "Save", "Lock"};

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
    Resource* resource;

private:
    void paint();

};

#endif // INSTRUCTIONITEM_H
