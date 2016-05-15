#ifndef MISS_H
#define MISS_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "mainwindow.h"

class Miss : public QObject , public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Miss(QGraphicsItem *parent=0);
private slots:
    void move();
};

#endif // MISS_H
