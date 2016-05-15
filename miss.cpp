#include "Miss.h"
#include "stdlib.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>

void Miss::Miss(QGraphicsItem *parent) : QObject() , QGraphicsPixmapItem(parent){
    QPixmap pic;
    pic.load(":/img/miss.png");
    setPixmap(pic);
    setPos(50,175);

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(10);
}

void Miss::move(){
    setPos(x()+10,y()+5);
    if(x()>500){
        scene()->removeItem(this);
        delete this;
    }
}
