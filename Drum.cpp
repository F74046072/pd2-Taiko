#include "Drum.h"
#include "stdlib.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>

extern MainWindow *m;

Drum::Drum(QGraphicsItem *parent) : QObject() , QGraphicsPixmapItem(parent){
    QPixmap pic;
    int randnum=rand()%2;

    if(randnum==0){
        pic.load(":/img/red.png");
        mode=0;
    }
    else if(randnum==1){
        pic.load(":/img/blue.png");
        mode=1;
    }

    setPixmap(pic);
    setPos(780,190);

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(10);
}

void Drum::move(){
    setPos(x()-2.5,y());
    if(x()>30&&x()<110){
        setFocus();
    }
    if(x()<10){
        miss();
    }
}

void Drum::keyPressEvent(QKeyEvent *keyevent){
    if(mode==0&&keyevent->key()==Qt::Key_F){
        m->don->play();
        if(x()>60&&x()<80) hitgood();
        else if(x()>40&&x()<100) hitok();
        else if(x()>30&&x()<110) miss();
    }
    else if(mode==1&&keyevent->key()==Qt::Key_J){
        m->ka->play();
        if(x()>60&&x()<80) hitgood();
        else if(x()>40&&x()<100) hitok();
        else if(x()>30&&x()<110) miss();
    }
}

void Drum::hitok(){
    m->scoreplus();
    m->okshow();
    scene()->removeItem(this);
    delete this;
}

void Drum::hitgood(){
    m->scoreplus();
    m->goodshow();
    scene()->removeItem(this);
    delete this;
}

void Drum::miss(){
    m->missshow();
    scene()->removeItem(this);
    delete this;
}
