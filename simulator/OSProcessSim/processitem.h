#ifndef PROCESSITEM_H
#define PROCESSITEM_H
#include <QFrame>
#include <QGraphicsScene>
#include <instructionitem.h>
#include "process.h"

class ProcessItem: public QFrame
{
    Q_OBJECT
public:
    ProcessItem(QWidget * parent = 0);
    virtual ~ProcessItem();
    void addInstructionItem(InstructionItem *iI);
    void highlight(bool);
    bool isFinished();
    std::string step();
    void selectNextInstruction();
signals:
    void sendSelection(ProcessItem*);
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
private:
    QGraphicsView *view;
    QGraphicsScene *scene;
    QRectF *border;
    QList<InstructionItem *> instructionItems;

    InstructionItem *currentInstruction;
};

#endif // PROCESSITEM_H
