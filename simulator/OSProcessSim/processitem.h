#ifndef PROCESSITEM_H
#define PROCESSITEM_H
#include <QFrame>
#include <QGraphicsScene>
#include <instructionitem.h>
#include "process.h"
#include <QVBoxLayout>

class ProcessItem: public QFrame
{
    Q_OBJECT
public:
    ProcessItem(QWidget * parent = 0);
    virtual ~ProcessItem();
    void addInstructionItem(InstructionItem *iI);
    QList<InstructionItem *> getInstructions();
    bool isFinished();
    std::string step();
    void selectNextInstruction();
    void highlight(bool);
signals:
    void sendSelection(ProcessItem*);
protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    InstructionItem *currentInstruction;
    QVBoxLayout *layout;
};

#endif // PROCESSITEM_H
