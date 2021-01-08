#ifndef PROCESSGRAPH_H
#define PROCESSGRAPH_H
#include <QFrame>


class ProcessGraph: public QFrame
{
public:
    ProcessGraph(int index, QWidget * parent = 0);
    virtual ~ProcessGraph();
protected:
    void paintEvent(QPaintEvent *event) override;
private:
};

#endif // PROCESSGRAPH_H
