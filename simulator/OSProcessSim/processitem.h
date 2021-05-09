#ifndef PROCESSITEM_H
#define PROCESSITEM_H
#include <QFrame>
#include <QGraphicsScene>
#include <instructionitem.h>
#include <QVBoxLayout>

class ProcessItem: public QFrame
{
    Q_OBJECT
public:
    ProcessItem(QWidget * parent = 0);
    virtual ~ProcessItem();
    void addInstructionItem(InstructionItem *iI);
    QList<InstructionItem *> getInstructions() const;
    void removeSelectedInstruction();
    bool isFinished();
    std::string step();
    void selectNextInstruction();
    void highlight(bool);
    int getTotalCycles() const;
    int getCycles() const;
    void reset();

signals:
    void sendSelection(ProcessItem*);

private slots:
    void selectInstruction(InstructionItem*);

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    InstructionItem* currentInstruction;
    InstructionItem* selectedInstruction;
    QVBoxLayout* layout;
};

#endif // PROCESSITEM_H
