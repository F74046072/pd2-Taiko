#ifndef DRUM_H
#define DRUM_H

#include "mainwindow.h"
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Drum : public QObject , public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Drum(QGraphicsItem *parent=0);
    void keyPressEvent(QKeyEvent *keyevent);
    void hitok();
    void hitgood();
    void miss();
private slots:
    void move();
private:
    int mode;
};

#endif // DRUM_H
