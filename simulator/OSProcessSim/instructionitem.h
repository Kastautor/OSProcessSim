#ifndef INSTRUCTIONITEM_H
#define INSTRUCTIONITEM_H

#include <QPushButton>
#include <QMouseEvent>

enum InstructionTypes { Operation, Load, Save};

class InstructionItem : public QPushButton
{
public:
    InstructionItem(InstructionTypes type, QWidget * parent = 0);
    void step();
    bool isFinished();
    void highlight(bool);
    InstructionItem* getSelectedInstructionItem();
    int getTotalCycles() const;
    int getCycles() const;
    InstructionTypes getType();
    void reset();

signals:
    void sendSelection(InstructionItem*);

protected:
    virtual void paintEvent(QPaintEvent *) override;

    QColor color;
    InstructionTypes type;
    int totalCycles;
    int cycles;
    bool selected;
private:
    void paint();
};

#endif // INSTRUCTIONITEM_H
