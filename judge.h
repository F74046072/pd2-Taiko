/*#ifndef JUDGE_H
#define JUDGE_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QTimer>
#include "mainwindow.h"
#include "Drum.h"

class Judge : public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    Judge(QGraphicsItem *parent=0);
    void keyPressEvent(QKeyEvent *keyevent;
private slots:
    void makedrum();
private:
    QTimer *timer;
    int time;
};

#endif // JUDGE_H
*/
