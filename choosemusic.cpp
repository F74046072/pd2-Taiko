#include "choosemusic.h"
#include "ui_choosemusic.h"

extern MainWindow *m;

ChooseMusic::ChooseMusic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseMusic)
{
    ui->setupUi(this);
    ui->music1->setGeometry(50,30,500,50);
    ui->music2->setGeometry(50,100,500,50);
    ui->music3->setGeometry(50,170,500,50);
    ui->music4->setGeometry(50,240,500,50);
    ui->music5->setGeometry(50,310,500,50);
}

ChooseMusic::~ChooseMusic()
{
    delete ui;
}
void ChooseMusic::on_music1_clicked(){
    m->music->stop();
    m->music->setMedia(QUrl("qrc:/music/girigiri.mp3"));
    m->game();
    close();
}

void ChooseMusic::on_music2_clicked(){
    m->music->stop();
    m->music->setMedia(QUrl("qrc:/music/bluemoment.mp3"));
    m->game();
    close();
}

void ChooseMusic::on_music3_clicked(){
    m->music->stop();
    m->music->setMedia(QUrl("qrc:/music/eonian.mp3"));
    m->game();
    close();
}

void ChooseMusic::on_music4_clicked(){
    m->music->stop();
    m->music->setMedia(QUrl("qrc:/music/godknows.mp3"));
    m->game();
    close();
}

void ChooseMusic::on_music5_clicked(){
    m->music->stop();
    m->music->setMedia(QUrl("qrc:/music/hero.mp3"));
    m->game();
    close();
}
