#ifndef PROCESSITEM_H
#define PROCESSITEM_H
#include <QFrame>
#include <QGraphicsScene>
#include <instructionitem.h>

class ProcessItem: public QFrame
{
public:
    ProcessItem(QWidget * parent = 0);
    virtual ~ProcessItem();
    void addInstructionItem(InstructionItem *iI);
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void highlight();
private:
    QGraphicsView *view;
    QGraphicsScene *scene;
};

#endif // PROCESSITEM_H
